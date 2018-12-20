#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Must provide an input file.";
	}

	std::ifstream infs (argv[1], std::ifstream::in);
	int val;
	int sum;
	int nlines = 0;
	std::string line;
	std::getline(infs, line);
   	while (infs.good()) {
		++nlines;
		//val << infs;
		std::stringstream ss(line);
		ss >> val;
		sum += val;
		std::getline(infs, line);
	}
	std::cout << "Lines: " << nlines << " Sum: " << sum << "\n";
}
