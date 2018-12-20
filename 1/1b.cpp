#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>


int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Must provide an input file." << "\n";
		exit(1);
	}

	std::ifstream infs (argv[1], std::ifstream::in);

	int val;
	int sum = 0;
	int nlines = 0;
	int nrepeats = 0;
	bool done = false;

	std::vector<int> inlist;
	std::unordered_set<int> freqs;
	freqs.emplace(sum);	// Starting point counts as a value.

	std::string line;
	std::getline(infs, line);

   	while (infs.good()) {
		++nlines;
		//val << infs;
		std::stringstream ss(line);
		ss >> val;
		inlist.push_back(val);
		sum += val;
		//std::cerr<< "val:"<<val<<" sum:"<<sum<<"\n";
		if (!freqs.emplace(sum).second) {
			done = true;
			break;
		}
		std::getline(infs, line);
	}
	std::cerr << "inlist size: " << inlist.size() << "\n";

	while (!done ) {
		++nrepeats;
		//std::cerr<< "nrepeats:"<<nrepeats<<"\n";

		for (int i : inlist) {
			sum += i;
			//std::cerr<< "val:"<<i<<" sum:"<<sum<<"\n";
			if (!freqs.emplace(sum).second) {
				done = true;
				break;
			}
		}
	}
	std::cout << "Lines: " << nlines << " Sum: " << sum << " Repeats: "
	   	<< nrepeats << "\n";

	return 0;
}
