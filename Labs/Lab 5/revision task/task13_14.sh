#!/bin/bash

read -p "Enter the filename: " filename

if [[ -f "$filename" ]]; then
    line_count=$(wc -l < "$filename")
    echo "Number of lines in '$filename': $line_count"

    echo "Contents of the file:"
    cat "$filename"
else
    echo "File '$filename' not found."
fi

