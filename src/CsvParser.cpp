#include "CsvParser.h"
#include <cassert>

std::vector<std::string> ParseFile(const std::string &path) 
{
	std::fstream fileStream;

	// not sure why I need to use c_str for this. Maybe because path is a ref?
	fileStream.open(path.c_str(), std::ios::in); 

	assert(fileStream.is_open()); // assert that fstream open worked

	std::string line;

	std::vector<std::string> lines = std::vector<std::string>();		

	while (getline(fileStream, line)) // parsing into string happens here until filestream is empty
    {		
		lines.push_back(line); // add the next line into vector		
	}

	assert(lines.size() == 500);// assert 500 lines are printed

	return lines;
}

int main()
{
    std::vector<std::string> students = ParseFile("/home/cuser/Desktop/CSVParseMidterm/sample.csv"); 
	// students now contains lines vector	

	int studentNumber = 1;

	for (int i = 0; i < students.size(); i++) 
    {
		// assert that each line follows the sample format
		assert(students[i] == studentNumber + ",Student,McStudentface,mmcstudentface@school.edu" == 0); 
		std::cout << students[i] << std::endl; // print it baby
		studentNumber++;
	}

	assert(students.size() == 500); // assert 500 lines are printed

}
