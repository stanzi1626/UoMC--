#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>

template <typename T>
std::string num_to_string(T i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

void print_data(std::vector<std::string> &course_name, std::vector<int> &course_code,
                std::vector<float> &course_mark, std::set<int> &indices)
{
    if (indices.size() == 0) {
        for (unsigned int i = 0; i < course_name.size(); i++) {
            std::cout << num_to_string(course_mark[i]) + " PHYS" + num_to_string(course_code[i])\
            + " " + course_name[i] << std::endl;
        }
    } else {
        for (std::set<int>::iterator it = indices.begin(); it != indices.end(); ++it) {
            std::cout << num_to_string(course_mark[*it]) + " PHYS" + num_to_string(course_code[*it])\
            + " " + course_name[*it] << std::endl;
        }
    }
}

int get_file_size()
{
    int size = 0;

    std::fstream file;
    file.open("courselist.dat");
    while (!file.eof()) {
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
    std::cout << "File read successfully" << std::endl;
}

void calculate_statistical_data(std::vector<float> &marks, std::set<int> &indices)
{
    float mean = 0;
    float standard_deviation = 0;
    float standard_error_of_mean = 0;

    if (indices.size() == 0) {
        for (unsigned int i = 0; i < marks.size(); i++) {
            mean += marks[i];
        }
        mean /= marks.size();

        for (unsigned int i = 0; i < marks.size(); i++) {
            standard_deviation += pow(marks[i] - mean, 2);
        }
        standard_deviation /= marks.size();
        standard_deviation = sqrt(standard_deviation);
        standard_error_of_mean = standard_deviation / sqrt(marks.size());
    } else {
        for (std::set<int>::iterator it = indices.begin(); it != indices.end(); it++) {
            mean += marks[*it];
        }
        mean /= indices.size();

        for (std::set<int>::iterator it = indices.begin(); it != indices.end(); it++) {
            standard_deviation += pow(marks[*it] - mean, 2);
        }
        standard_deviation /= indices.size();
        standard_deviation = sqrt(standard_deviation);
        standard_error_of_mean = standard_deviation / sqrt(indices.size());
    }
    std::cout << std::endl << "Mean: " << mean << std::endl;
    std::cout << "Standard deviation: " << standard_deviation << std::endl;
    std::cout << "Standard error of mean: " << standard_error_of_mean << std::endl << std::endl;
}

void filter_year(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, std::set<int> &indices, int year, int file_size)
{
    if (indices.size() != 0) {
        for (std::set<int>::iterator it = indices.begin(); it != indices.end();) {
            if (course_code[*it] / 10000 != year) {
                indices.erase(it++);
            } else {
                ++it;
            }
        }
    }
    if (indices.size() == 0) {
        for (unsigned int i = 0; i < file_size; i++) {
            if (course_code[i] / 10000 == year) {
                indices.insert(i);
            }
        }
    } 
}

void filter_mark(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, std::set<int> &indices, float mark, int file_size)
{
    if (indices.size() != 0) {
        for (std::set<int>::iterator it = indices.begin(); it != indices.end();) {
            if (course_mark[*it] < mark) {
                indices.erase(it++);
            } else {
                ++it;
            }
        }
    }
    if (indices.size() == 0) {
        for (unsigned int i = 0; i < file_size; i++) {
            if (course_mark[i] >= mark) {
                indices.insert(i);
            }
        }
    }
}

void sort_mark_into_descending_order(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, int file_size)
{
    for (unsigned int i = 0; i < file_size; i++) {
        for (unsigned int j = i + 1; j < file_size; j++) {
            if (course_mark[i] < course_mark[j]) {
                std::swap(course_mark[i], course_mark[j]);
                std::swap(course_code[i], course_code[j]);
                std::swap(course_name[i], course_name[j]);
            }
        }
    }
    std::cout << "Successfully sorted mark of courses into descending order" << std::endl;
}

void sort_name_into_alphabetical_order(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, int file_size)
{
    for (unsigned int i = 0; i < file_size; i++) {
        for (unsigned int j = i + 1; j < file_size; j++) {
            if (course_name[i] > course_name[j]) {
                std::swap(course_mark[i], course_mark[j]);
                std::swap(course_code[i], course_code[j]);
                std::swap(course_name[i], course_name[j]);
            }
        }
    }
    std::cout << "Successfully sorted name of courses into alphabetical order" << std::endl;
}

void sort_code_into_ascending_order(std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, int file_size)
{
    for (unsigned int i = 0; i < file_size; i++) {
        for (unsigned int j = i + 1; j < file_size; j++) {
            if (course_code[i] > course_code[j]) {
                std::swap(course_mark[i], course_mark[j]);
                std::swap(course_code[i], course_code[j]);
                std::swap(course_name[i], course_name[j]);
            }
        }
    }
    std::cout << "Successfully sorted code of courses into ascending order" << std::endl;
}

void year_check(int &year)
{
    do {
        std::cin >> year;

        if (year < 1 || year > 4 || std::cin.fail()) {
            std::cout << "Please enter a valid year between 1-4" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        } else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            break;
        }
    } while (true);
}

void mark_check(float &mark)
{
    do {
        std::cin >> mark;

        if (mark < 0 || mark > 100 || std::cin.fail()) {
            std::cout << "Please enter a valid mark between 0-100" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        } else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            break;
        }
    } while (true);
}

void print_sort_menu()
{
    std::cout << std::endl << "1. Sort by mark" << std::endl;
    std::cout << "2. Sort by name" << std::endl;
    std::cout << "3. Sort by code" << std::endl << std::endl;
}

void sort_menu_check(int &sort_option)
{
    do {
        std::cin >> sort_option;

        if (sort_option < 1 || sort_option > 3 || std::cin.fail()) {
            std::cout << "Please enter a valid option" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        } else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            break;
        }
    } while (true);
}

void sort_menu_options(int &sort_option, std::vector<std::string> &course_name, std::vector<int> &course_code,
               std::vector<float> &course_mark, int file_size)
{
    switch (sort_option) {
        case 1:
            sort_mark_into_descending_order(course_name, course_code, course_mark, file_size);
            break;
        case 2:
            sort_name_into_alphabetical_order(course_name, course_code, course_mark, file_size);
            break;
        case 3:
            sort_code_into_ascending_order(course_name, course_code, course_mark, file_size);
            break;
    }
}

void print_main_menu()
{
    std::cout << std::endl << "1. Filter by year" << std::endl;
    std::cout << "2. Filter by mark" << std::endl;
    std::cout << "3. Print" << std::endl;
    std::cout << "4. Reset and sort again" << std::endl;
    std::cout << "5. Exit" << std::endl << std::endl;
}

int main_menu_check(int &menu_option)
{
    do
    {
        std::cin >> menu_option;

        if (menu_option < 1 || menu_option > 7 || std::cin.fail()) {
            std::cout << "Please enter a valid option" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        } else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            break;
        }
    } while (true);
    return menu_option;
}

void main_menu_options(int menu_option, std::vector<std::string> &course_name, std::vector<int> &course_code,
                       std::vector<float> &course_mark, std::set<int> &indices, int file_size)
{
    switch (menu_option) {
    case 1:
        std::cout << "Enter a year to filter (between 1-4): " << std::endl;
        int year;
        year_check(year);
        filter_year(course_name, course_code, course_mark, indices, year, file_size);
        break;
    case 2:
        std::cout << "Enter a mark to filter (between 0-100): " << std::endl;
        float mark;
        mark_check(mark);
        filter_mark(course_name, course_code, course_mark, indices, mark, file_size);
        break;
    case 3:
        print_data(course_name, course_code, course_mark, indices);
        calculate_statistical_data(course_mark, indices);
        break;
    case 4:
        indices.clear();
        int sort_option;
        print_sort_menu();
        sort_menu_check(sort_option);
        std::cout << "You picked option: " << sort_option << std::endl;
        sort_menu_options(sort_option, course_name, course_code, course_mark, file_size);
        break;
    case 5:
        std::cout << "Exiting..." << std::endl;
        break;
    }
}

void print_divider()
{
    std::cout << "----------------------------------------" << std::endl;
}

int main()
{
    int file_size = get_file_size();

    std::vector<std::string> root_course_name;
    std::vector<int> root_course_code;
    std::vector<float> root_course_mark;
    std::set<int> indices;

    read_file(root_course_name, root_course_code, root_course_mark);

    int sort_option;
    print_sort_menu();
    sort_menu_check(sort_option);
    std::cout << "You picked option: " << sort_option << std::endl;
    sort_menu_options(sort_option, root_course_name, root_course_code, root_course_mark, file_size);

    int menu_option;
    while(true) {
        print_divider();
        print_main_menu();
        main_menu_check(menu_option);
        std::cout << "You picked option: " << menu_option << std::endl << std::endl;
        main_menu_options(menu_option, root_course_name, root_course_code, root_course_mark, indices, file_size);

        if (menu_option == 5) {
            break;
        }
    }
    return 0;
}