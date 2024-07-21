# Architecture

This document describes the architecture of the project. It mainly delves into the code side of things and not the overall project structure.

## Before we start

The project is aiming at being as simple to set up as possible. For that reason I created the `init.` script. You just have to make it executable and run it. It will install all the dependencies and set up the project for you. It will then create a simple executable of the project that you can run. The philosophy is to have no friction when setting up the project. As we all know, there is nothing more annoying than having to set up a project for hours before you can even run it.

There are various self-explanatory scripts in the `scripts` folder. I wont dive deep into them. They are here and you can look at them individually.

## The code in `src/`

### The Command System

The core of the project is the *command system*. It follows the [Command Pattern](https://gameprogrammingpatterns.com/command.html). The entire application is run by the commands. Meaning not just gameplay but also all the rendering or input handling is reduced to the commands. The reason is to have a central place where all the main flow is. The command system revolves around the `Invoker` class. The `Invoker` is a singleton as I want one central place for the commands to go to.

The `Invoker` has a *priority  queue*. Each event has a priority in which it is executed. The reason for this is to make sure that if some very important command gets submitted to the `Invoker` we get it resolved as soon as possible. The highest priority is usually given to *critical exceptions* which require the application to be terminated immediately. So there is no reason to handle redundant commands if the application is going to be terminated anyway.

The `Invoker` waits for commands so the application is not running at 100% CPU usage all the time. It only runs when necessary. The events can either be processed all at once or in *batches* in a given time period. This is because when we can process everything when frame rate is not important so it doesn't matter if the application responds a few milliseconds later. But when in game the frame rate is important so we want to process the commands in batches and in a given time period to respect the frames per second.

### Application

The `Application` class is the main class of the project. It is the class within which everything happens. The class gets created in the `main` function and then the `Application` class runs the game loop. The `Application` class is responsible for everything. It is the CEO of the project. It makes sure that the application logic is progressing as expected and that all undefined behavior is handled correctly.

The main loop occurs within the `run()` method. It makes sure that the application is running when it should and is terminated when it should. The `run()` method is the heart of the project. It gives the beets via it's iterations to the rest of the code.

The `run()` method runs only when the *health flag* allows it to. The *health flag* is a simple way to check the status of the application and if something went wrong and how the application should deal with it. The application's health is dependent on the status of assets, the exceptions that occurred and various other factors.

The `Application` also contains the `controlFlow()` method which makes sure the commands are processed as they should be. That is based on the context of the application. I briefly mentioned before that there are some batches. Well that depends on the context of the application. If the application can afford to process all the commands at once it will do so. If not it will process them in batches and in a specified time period.


### Thread manager

The `Application` has a lot of systems it needs to stay afloat and running. For that reason the various aspects of the `Application` are divided into several *types* which are then used by the `ThreadManager` to dedicate each type a specific thread. The `ThreadManager` is responsible for managing the threads and their life cycles. It is a singleton as we want one central place for the threads to go to.

The `ThreadManager` receives a `Task` object which is then executed. In practice it means that the `Invoker` when it executes the command it creates a `Task` object which is then sent to the `ThreadManager` to be executed. The `ThreadManager` then decides which thread to use to execute the `Task` object. The `ThreadManager` itself has a thread to make sure it is running and managing the threads as it should.

The `ThreadManager` has a *priority queue* for the `Task` objects. The `Task` objects are executed based on their priority. The highest priority is given to the *critical exceptions* which require the application to be terminated immediately. The *thread system* and *command system* are very similar in their functionality.