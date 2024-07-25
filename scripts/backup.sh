#!/bin/bash
# Backup script for the git project

# Check if the correct number of arguments is passed
if [ "$#" -ne 1 ]; then
	echo "[Error] Usage: ./scripts/backup.sh <backup_directory>"
	exit 1
fi

# The directory where the backup will be stored
BACKUP_DIR=$1

# Exit immediately if a command exits with a non-zero status.
set -e

# Define the name of the backup file
DATE=$(date +%Y-%m-%d-%H%M%S)
BACKUP_FILENAME="DungeonLife_backup_$DATE.tar.gz"

# Create the backup directory if it doesn't exist
if [ ! -d "$BACKUP_DIR" ]; then
	echo "Creating backup directory at $BACKUP_DIR..."
	mkdir -p "$BACKUP_DIR"
fi

# The path to the backup file
BACKUP_FILEPATH="$BACKUP_DIR/$BACKUP_FILENAME"

echo "Starting backup of the Dungeon Life project..."

# Use tar to create a gzipped archive of the project directory
# --exclude-vcs ignores version control system directories
# --exclude-from reads patterns to ignore from .gitignore
tar --exclude-vcs --exclude-from='.gitignore' -czf "$BACKUP_FILEPATH" .
echo "Backup completed: $BACKUP_FILEPATH"