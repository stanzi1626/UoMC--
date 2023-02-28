#include <iostream>
#include <cmath>

enum hubble_type {
    E0, E3, E5, E7, S0, Sa, Sb, Sc, SBa, SBb, SBc, Irr
};

std::ostream& operator<<(std::ostream& os, const hubble_type ht)
{
  switch(ht)
  {
    case hubble_type::E0: os << "E0"; break;
    case hubble_type::E3: os << "E3"; break;
    case hubble_type::E5: os << "E5"; break;
    case hubble_type::E7: os << "E7"; break;
    case hubble_type::S0: os << "S0"; break;
    case hubble_type::Sa: os << "Sa"; break;
    case hubble_type::Sb: os << "Sb"; break;
    case hubble_type::Sc: os << "Sc"; break;
    case hubble_type::SBa: os << "SBa"; break;
    case hubble_type::SBb: os << "SBb"; break;
    case hubble_type::SBc: os << "SBc"; break;
    case hubble_type::Irr: os << "Irr"; break;
  }
  return os;
}

class Galaxy {
private:
    hubble_type galaxy_type;
    double total_mass;
    double stellar_mass_fraction;
    double redshift;

public:
    Galaxy()
    {
        std::cout << "Galaxy()" << std::endl;
    }

    Galaxy(hubble_type galaxy_type, double total_mass, double stellar_mass_fraction, double redshift)
    : galaxy_type(galaxy_type), total_mass(total_mass), stellar_mass_fraction(stellar_mass_fraction), redshift(redshift)
    {
        std::cout << "Galaxy(hubble_type, double, double, double)" << std::endl;
    }

    ~Galaxy()
    {
        std::cout << "~Galaxy()" << std::endl;
    }

    void print_stellar_mass()
    {
        std::cout << "Stellar mass: " << pow(10, total_mass) * stellar_mass_fraction << " solar masses" << std::endl;
    }

    void print_galaxy_data()
    {

        std::cout << "Galaxy type: " << galaxy_type << std::endl;
        std::cout << "Total mass: " << pow(10, total_mass) << " solar masses" << std::endl;
        std::cout << "Stellar mass fraction: " << stellar_mass_fraction << std::endl;
        std::cout << "Redshift: " << redshift << std::endl;
    }
};

// void galaxy_type_check(hubble_type &galaxy_type) 
// {
//     do {
//         std::cout << "Please enter the galaxy type: " << std::endl;
//         std::cin >> galaxy_type;
//         if (std::cin.fail() || std::cin.peek() != '\n') {
//             std::cout << "Invalid galaxy type, please try again" << std::endl;
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         } else {
//             break;
//         }
//     } while (true);
// }

void total_mass_check(double &total_mass)
{
    do {
        std::cout << "Please enter the total mass: " << std::endl;
        std::cin >> total_mass;
        if (total_mass < 7 || total_mass > 12 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Invalid total mass, please try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

void stellar_mass_fraction_check(double &stellar_mass_fraction)
{
    do {
        std::cout << "Please enter the stellar mass fraction: " << std::endl;
        std::cin >> stellar_mass_fraction;
        if (stellar_mass_fraction < 0 || stellar_mass_fraction > 0.05 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Invalid stellar mass fraction, please enter a value between [0, 0.05]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

void redshift_check(double &redshift)
{
    do {
        std::cout << "Please enter the redshift: " << std::endl;
        std::cin >> redshift;
        if (redshift < 0 || redshift > 10 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Invalid redshift, please enter a value in the range [0, 10]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

void answer_check(char &answer)
{
    do {
        std::cin >> answer;
        if (answer != 'n' && answer != 'N' && answer != 'y' && answer != 'Y' || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Invalid answer, please enter y/n" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

int main() {
    hubble_type galaxy_type;
    double total_mass;
    double stellar_mass_fraction;
    double redshift;

    std::cout << "Would you like to input your own galaxy data? [y/n] \n (If no, then a random galaxy will be made) \n"\
    << "Input: ";
    char answer;
    answer_check(answer);

    if (answer == 'y' || answer == 'Y') {
        // galaxy_type_check(galaxy_type);
        total_mass_check(total_mass);
        stellar_mass_fraction_check(stellar_mass_fraction);
        redshift_check(redshift);
    } else {
        srand(time(0));
        galaxy_type = static_cast<hubble_type>(rand() % 12);
        total_mass = 7 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (12 - 7)));
        stellar_mass_fraction = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (0.05 - 0)));
        redshift = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (10 - 0)));
    }

    Galaxy galaxy(galaxy_type, total_mass, stellar_mass_fraction, redshift);
    galaxy.print_stellar_mass();
    galaxy.print_galaxy_data();

    return 0;
}