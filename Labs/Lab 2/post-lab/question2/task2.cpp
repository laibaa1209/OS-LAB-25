#include<iostream>
#include<fstream>
//input is supposd to be given in series
int main(int argc, char* argv[]){
	if(argc < 2) {
		std::cerr << "Usuage: " <<argv[0] << " <num1>, <num2>....<numN>\n";
		return 1;
	}
	int array[argc];

	for(int i = 0; i < argc; i++){
		array[i] = std::atoi(argv[i]);
	}

	int diff = array[1]-array[0];
	int missingElement = 0;

	for(int  i = 0; i < argc; i++){
		if(array[i+1] - array[i] != diff) {
			missingElement = array[i] + diff;
			break;
		}
	}
	std::cout<< "Missing Element: " << missingElement <<std::endl;

	std::ofstream file("missingElement.txt");
	if(!file){
		std::cerr<< "file doesnot exists" << std::endl;
	}

	file << "The missing element is: " << missingElement <<std::endl;

	std::cout<<" missing element written to missingElement.txt" <<std::endl; 


return 0;
}
