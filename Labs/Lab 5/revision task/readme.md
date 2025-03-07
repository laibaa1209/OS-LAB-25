# TASK 1-14
### 1. Create a directory called project in your home directory.
mkdir ~/project

### 2. Navigate to the project directory.
cd ~/project

### 3. Create an empty file named task1.txt.
touch task1.txt

### 4. List all files in the current directory.
ls

### Create a file named file1.txt.
touch file1.txt

### 5. Change permissions of file1.txt so only the owner has read and write permissions.
chmod 600 file1.txt

### 6. Check the permissions of file1.txt.
ls -l file1.txt

### 7. Grant execute permissions to the owner of file1.txt.
        chmod u+x file1.txt

### 8. Display the current working directory.
pwd

### 9. Show the current date and time.
date

### 10. Display system’s disk usage.
df -h

### 11. Display system uptime.
uptime

### 12. Show all users currently logged into the system.
who

### 13 & 14. Script to take a filename as input and count lines in the file.
echo -e '#!/bin/bash\nread -p "Enter filename: " file\nwc -l "$file"' > count_lines.sh
chmod +x count_lines.sh

