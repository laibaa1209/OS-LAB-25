read -p"Enter a sentence: " sent
echo "$sent"
length=${#sent}
echo "the length is string is $length"

count=0
vowels="aeiouAeiou"
for(( i=0;i<length;i++ )); do
	char="${sent:i:1}"
	if [[ $vowels == *"$char"* ]]; then
		((count++))
	fi
done
echo "The number of vowels in the sentence is: $count"
