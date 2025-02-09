#include<iostream>
#include<fstream>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		std::cerr << "Usuage: " << argv[0] << "<filename>\n";
		return 1; //no file name passed error
	}

	std::ifstream file(argv[1]);

	if(!file) {
		std::cerr << "File couldn't be openend or the file does not exists!" << argv[1];
		return 1;
	}

	std::string line;
	while(std::getline(file, line)){
		std::cout<< line << std::endl;
	}

	file.close();
	return 0;
}
