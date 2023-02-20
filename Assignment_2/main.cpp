#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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

void read_file(std::vector<std::string> &course_list, std::vector<int> &course_code, std::vector<float> &course_mark)
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

        ss >> mark >> code >> name;

        course_list.push_back(name);
        course_code.push_back(code);
        course_mark.push_back(mark);
    }
    file.close();
}

int main()
{
    int file_size = get_file_size();

    std::vector<std::string> course_list;
    std::vector<int> course_code;
    std::vector<float> course_mark;


    return 0;
}