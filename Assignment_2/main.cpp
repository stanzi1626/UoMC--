// • Write a program to read the data and compute the mean, standard deviation and
// standard error of the mean for the coursework marks.
// • The code should determine the number of data entries in the file. DONE
// • You must either use new to allocate an array or if you know how to use to, use
// vectors as required for part 2.
// • Be efficient in storage. You now have to use vectors for storage.
// • Use a string stream to create a string containing the full course title e.g.
//  PHYS 30762 Object-Oriented Programming in C++
// • Each of these strings should be stored in a single vector.
// • Print out the full course list using an iterator.
// • Your code should be able to print out a list of courses for a particular year, as
// identified by the first digit of the course code, including the mean and standard
// deviation for those courses.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vec) {
		for (unsigned int j = 0; j < vec.size(); j++) {
			out << '[' << vec[j] << ']' << std::endl;
		}
		return out;
	}

int get_file_size()
{
    int size = 0;

    std::fstream file;
    file.open("courselist.dat");
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        if (line == "") continue;
        size++;
    }
    file.close();

    std::cout << "File size: " << size << std::endl;

    return size;
}

void read_file(std::vector<std::string> &course_name, std::vector<int> &course_code, std::vector<float> &course_mark)
{
    std::fstream file;
    file.open("courselist.dat");
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        if (line == "") continue;

        std::stringstream ss(line);
        std::string name;
        int code;
        float mark;

        ss >> mark >> code >> std::ws;

        course_mark.push_back(mark);
        course_code.push_back(code);

        std::getline(ss, name, '\n');

        course_name.push_back(name);
    }
    file.close();
}

void calculate_statistical_data(std::vector<float> &course_mark)
{
    float mean = 0;
    float standard_deviation = 0;
    float standard_error_of_mean = 0;

    for (int i = 0; i < course_mark.size(); i++)
    {
        mean += course_mark[i];
    }
    mean /= course_mark.size();

    for (int i = 0; i < course_mark.size(); i++)
    {
        standard_deviation += (course_mark[i] - mean) * (course_mark[i] - mean);
    }
    standard_deviation /= course_mark.size();
    standard_deviation = sqrt(standard_deviation);

    standard_error_of_mean = standard_deviation / sqrt(course_mark.size());

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standard deviation: " << standard_deviation << std::endl;
    std::cout << "Standard error on mean: " << standard_error_of_mean << std::endl;
}

int main()
{
    int file_size = get_file_size();

    std::vector<std::string> course_name;
    std::vector<int> course_code;
    std::vector<float> course_mark;

    read_file(course_name, course_code, course_mark);

    // Debug
    // std::cout << course_name << std::endl;
    calculate_statistical_data(course_mark);

    return 0;
}