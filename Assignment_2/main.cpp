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
#include <set>

void print_data(std::vector<std::string> &course_name, std::vector<int> &course_code,
                std::vector<float> &course_mark, std::set<int> &indices)
{
    for (std::set<int>::iterator it = indices.begin(); it != indices.end(); ++it)
    {
        std::cout << course_mark[*it] << " " << course_code[*it] << " " << course_name[*it] << std::endl;
    }
}

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

    std::cout << "File size: " << size <<  " entries" << std::endl;

    return size;
}

void read_file(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark)
{
    std::fstream file;
    file.open("courselist.dat");
    int index = 0;
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

void calculate_statistical_data(std::vector<float> &marks, std::set<int> &indices)
{
    float mean = 0;
    float standard_deviation = 0;
    float standard_error_of_mean = 0;

    for (std::set<int>::iterator it = indices.begin(); it != indices.end(); it++)
    {
        mean += marks[*it];
    }
    mean /= indices.size();

    for (std::set<int>::iterator it = indices.begin(); it != indices.end(); it++)
    {
        standard_deviation += pow(marks[*it] - mean, 2);
    }
    standard_deviation /= indices.size();
    standard_deviation = sqrt(standard_deviation);

    standard_error_of_mean = standard_deviation / sqrt(indices.size());

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standard deviation: " << standard_deviation << std::endl;
    std::cout << "Standard error of mean: " << standard_error_of_mean << std::endl;
}

void sort_year(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, std::set<int> &indices, int year, int file_size)
{
    if (indices.size() == 0) {
        for (int i = 0; i < file_size; i++) {
            if (course_code[i] / 10000 == year) {
                indices.insert(i);
            }
        }
    } else {
        for (std::set<int>::iterator it = indices.begin(); it != indices.end();) {
            if (course_code[*it] / 10000 != year) {
                indices.erase(it++);
            } else {
                ++it;
            }
        }
    }

    print_data(course_name, course_code, course_mark, indices);
    calculate_statistical_data(course_mark, indices);
}

void sort_mark(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, std::set<int> &indices, float mark, int file_size)
{
    if (indices.size() == 0) {
        for (int i = 0; i < file_size; i++) {
            if (course_mark[i] >= mark) {
                indices.insert(i);
            }
        }
    } else {
        for (std::set<int>::iterator it = indices.begin(); it != indices.end();) {
            if (course_mark[*it] < mark) {
                indices.erase(it++);
            } else {
                ++it;
            }
        }
    }

    print_data(course_name, course_code, course_mark, indices);
    calculate_statistical_data(course_mark, indices);
}

int main()
{
    int file_size = get_file_size();

    std::vector<std::string> root_course_name;
    std::vector<int> root_course_code;
    std::vector<float> root_course_mark;
    std::set<int> indices;

    read_file(root_course_name, root_course_code, root_course_mark);

    bool program_running = true;
    do
    {
        std::cout << "Enter a year to sort (between 1-4): ";
        int year;
        std::cin >> year;

        sort_year(root_course_name, root_course_code, root_course_mark, indices, year, file_size);

        std::cout << "Enter a mark: ";
        int mark;
        std::cin >> mark;

        sort_mark(root_course_name, root_course_code, root_course_mark, indices, mark, file_size);

        break;
    } while (program_running);
    
    

    // Debug
    // std::cout << root_indices << std::endl;
    // calculate_statistical_data(course_mark);

    return 0;
}