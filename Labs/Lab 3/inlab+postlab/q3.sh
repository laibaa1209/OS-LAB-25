read -p"Enter the file name: " filename

if [[ -f "$filename" ]]; then
	echo "The file $filename exists"
	current_time=$(date)
	echo "the current date and time is: $current_time" >> $filename
	echo "Current date and time added to the file"
else
	echo "The file $filename does not exist!" 
fi
