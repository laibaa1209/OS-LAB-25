#include<iostream>

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cerr << "Usuage: " << argv[0] << "<num1>,  <num2>....<numN>\n";
		return 1;
	}

	int array[argc];
	int sum = 0;
	int avg = 0;

	for(int i = 0; i < argc; i++){
		array[i] = std::atoi(argv[i]);
		sum +=  array[i];
	}
	avg = sum/(argc-1);
	std::cout<< "Sum: " <<sum << " Average: " <<avg <<std::endl;
return 0;
}
