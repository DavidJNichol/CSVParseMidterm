#include "CsvParser.h"

/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
std::vector<std::string> getLines(const std::string &path) 
{
	std::fstream fs;

	fs.open(path.c_str(), std::ios::in);

	std::vector<std::string> lines = std::vector<std::string>();

	std::string temp;
	std::string line;

	while (getline(fs, line)) 
    {
		//getline(fs, line);
		lines.push_back(line);
	}
	//std::move(lines);
	return lines;
}

int main()
{
    std::vector<std::string> gl = getLines("/home/cuser/Desktop/MidtermDavidNichol/sample.csv");

	for (int i = 0; i < gl.size()-10; i++) 
    {
		std::cout << gl[i] << std::endl;
	}

}
