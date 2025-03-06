read -p "Enter the path for the file or directory:" path

if [[ ! -e "$path" ]]; then
	echo "The file or directory does not exist"
fi

if [[ -f "$path" ]]; then
	echo "It is a file"
elif [[ -d "$path" ]]; then
	echo "It is a directory"
else
	echo "It is none"
fi


