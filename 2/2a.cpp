#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <memory>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Must provide an input file." << "\n";
		exit(1);
	}

	std::ifstream infs (argv[1], std::ifstream::in);

	std::vector<std::unique_ptr<char>> inlist;
	std::string line;
	size_t nlines = 0;

	std::getline(infs, line);
   	while (infs.good()) {
		++nlines;
		std::unique_ptr<char> cstr(new char[line.length()+1]);
		std::strcpy(cstr.get(), line.c_str());
		inlist.emplace_back(std::move(cstr));
		std::getline(infs, line);
	}
	std::cerr << "nlines: "<<nlines << " inlist.size: " << inlist.size() << "\n";

	size_t ntwo, nthree;
	for(auto& cstr : inlist) {
		// Verify we sucked it in properly:
		std::cerr << cstr.get() << "\n";

	}
//		for (int i : inlist) {
//			sum += i;
//			//std::cerr<< "val:"<<i<<" sum:"<<sum<<"\n";
//			if (!freqs.emplace(sum).second) {
//				done = true;
//				break;
//			}
//		}
//	}
//	std::cout << "Lines: " << nlines << " Sum: " << sum << " Repeats: "
//	   	<< nrepeats << "\n";
//
	return 0;
}
