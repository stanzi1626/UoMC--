#include <iostream>
#include <math.h>

const double conversion{1.602176634e-19};

double Bohr_energy(int n_initial, int n_final, int atomic_number) {
    return 13.6 * pow(atomic_number, 2) * (pow(n_final, -2) - pow(n_initial, -2));
}

bool answer_check(char answer) {
    if (answer == 'y' || answer == 'Y') {
        std::cin.ignore(256, '\n');
        return true;
    }
    else if (answer == 'n' || answer == 'N') {
        std::cin.ignore(256, '\n');
        return true;
    }
    else {
        std::cout << "Please enter a valid answer" << std::endl;
        std::cin.ignore(256, '\n');
        return false;
    }
}

bool input_check(int n_initial, int n_final, int atomic_number, char unit) {
    if (n_initial < 1 || n_final < 1 || atomic_number < 1 || std::cin.fail()) {
        std::cout << "Please enter a positive integer for n_initial >= 1, n_final >= 1, and atomic_number >= 1" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        return false;
    }
    else if (n_initial <= n_final) {
        std::cout << "Please enter a value for n_initial that is greater than n_final" << std::endl;
        return false;
    }
    else if (unit != 'e' && unit != 'E' && unit != 'j' && unit != 'J' || std::cin.fail()) {
        std::cout << "Please enter a valid unit" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        return false;
    }
    else {
        return true;
    }
}

void calculate_energy(int n_initial, int n_final, int atomic_number, char unit) {
    if (unit == 'e' || unit == 'E') {
        std::cout << Bohr_energy(n_initial, n_final, atomic_number) << " eV" << std::endl;
    }
    else if (unit == 'j' || unit == 'J') {
        std::cout << Bohr_energy(n_initial, n_final, atomic_number) * conversion << " J" << std::endl;
    }
}

int main() {
    int n_initial, n_final, atomic_number;
    char unit;
    char answer;

    bool input_check_var = false;
    bool answer_check_var = false;
    bool task = true;

    do {
        input_check_var = false;
        while(!input_check_var){
            std::cout << "Please enter the initial conditions and the desired unit (E/e for electronVolts and J/j for Joules)" << std::endl;
            std::cout << "in the form n_initial n_final atomic_number unit" << std::endl;
            std::cin >> n_initial >> n_final >> atomic_number >> unit;
            input_check_var = input_check(n_initial, n_final, atomic_number, unit);
            if (input_check_var == false) {
                std::cout << "Values entered were not valid, would you like to try again? [y/n]" << std::endl;
                answer_check_var = false;
                while (!answer_check_var) {
                    std::cin >> answer;
                    answer_check_var = answer_check(answer);
                }
                if (answer == 'n' || answer == 'N') {
                    std::cout << "Exiting program" << std::endl;
                    task = false;
                    break;
                }
            }
        }

        if (task) {
            std::cout << "The energy released by the electron is: " << std::endl;
            calculate_energy(n_initial, n_final, atomic_number, unit);

            std::cout << "Would you like to continue? [y/n]" << std::endl;
            answer_check_var = false;
            while (!answer_check_var) {
                std::cin >> answer;
                answer_check_var = answer_check(answer);
            }
            if (answer == 'n' || answer == 'N') {
                std::cout << "Exiting program" << std::endl;
                task = false;
                break;
            }
        }
    } while (task);

    return 0;
}