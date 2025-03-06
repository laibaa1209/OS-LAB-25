#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <directory_to_backup>"
  exit 1
fi

SOURCE_DIR="$1"

if [ ! -d "$SOURCE_DIR" ]; then
  echo "Error: Directory '$SOURCE_DIR' does not exist."
  exit 1
fi

BACKUP_DIR="/path/to/backup/$(basename "$SOURCE_DIR")_backup_$(date +%Y-%m-%d)"

mkdir -p "$BACKUP_DIR"

if [ ! -d "$BACKUP_DIR" ]; then
  echo "Error: Failed to create backup directory '$BACKUP_DIR'."
  exit 1
fi

echo "Starting backup of '$SOURCE_DIR' to '$BACKUP_DIR'..."
cp -r "$SOURCE_DIR"/* "$BACKUP_DIR"

NUM_FILES=$(find "$BACKUP_DIR" -type f | wc -l)
NUM_DIRS=$(find "$BACKUP_DIR" -type d | wc -l)

echo "Backup completed successfully!"
echo "Number of files backed up: $NUM_FILES"
echo "Number of directories backed up: $NUM_DIRS"
echo "Backup location: $BACKUP_DIR"
