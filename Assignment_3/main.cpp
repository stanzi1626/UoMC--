#include <iostream>
#include <cmath>
#include <vector>

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

void print_enum_galaxy_values()
{
    std::cout << "E0: " << "0" << std::endl;
    std::cout << "E3: " << "1" << std::endl;
    std::cout << "E5: " << "2" << std::endl;
    std::cout << "E7: " << "3" << std::endl;
    std::cout << "S0: " << "4" << std::endl;
    std::cout << "Sa: " << "5" << std::endl;
    std::cout << "Sb: " << "6" << std::endl;
    std::cout << "Sc: " << "7" << std::endl;
    std::cout << "SBa: " << "8" << std::endl;
    std::cout << "SBb: " << "9" << std::endl;
    std::cout << "SBc: " << "10" << std::endl;
    std::cout << "Irr: " << "11" << std::endl;
}

class Galaxy {
private:
    hubble_type galaxy_type;
    double total_mass;
    double stellar_mass_fraction;
    double redshift;
    std::vector<Galaxy> satellites;

public:
    Galaxy()
    {
        std::cout << "Galaxy()" << std::endl;
    }

    Galaxy(hubble_type galaxy_type, double total_mass, double stellar_mass_fraction, double redshift)
    : galaxy_type(galaxy_type), total_mass(total_mass), stellar_mass_fraction(stellar_mass_fraction), redshift(redshift)
    {}

    ~Galaxy() {}

    void print_stellar_mass()
    {
        std::cout << "Stellar mass: " << pow(10, total_mass) * stellar_mass_fraction << " solar masses" << std::endl;
    }

    Galaxy create_random_galaxy(){
        hubble_type galaxy_type;
        double total_mass;
        double stellar_mass_fraction;
        double redshift;

        galaxy_type = static_cast<hubble_type>(rand() % 12);
        total_mass = 7 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (12 - 7)));
        stellar_mass_fraction = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (0.05 - 0)));
        redshift = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (10 - 0)));

        Galaxy galaxy(galaxy_type, total_mass, stellar_mass_fraction, redshift);
        return galaxy;
    }

    void add_satellites()
    {
        for (int i = 0; i < rand() % 10; i++) {
            satellites.push_back(create_random_galaxy());
        }
    }

    void print_galaxy_data()
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Galaxy type: " << galaxy_type << std::endl;
        std::cout << "Total mass: " << pow(10, total_mass) << " solar masses" << std::endl;
        std::cout << "Stellar mass fraction: " << stellar_mass_fraction << std::endl;
        std::cout << "Redshift: " << redshift << std::endl << std::endl;

        std::cout << "Number of satellites: " << satellites.size() << std::endl;
        for (auto itr = satellites.begin(); itr != satellites.end(); ++itr) {
            itr -> print_galaxy_data();
        }
    }

    void change_galaxy_type(hubble_type galaxy_type)
    {
        this->galaxy_type = galaxy_type;
    }
};

int main() {
    hubble_type galaxy_type;
    double total_mass;
    double stellar_mass_fraction;
    double redshift;

    srand(time(0));
    galaxy_type = static_cast<hubble_type>(rand() % 12);
    total_mass = 7 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (12 - 7)));
    stellar_mass_fraction = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (0.05 - 0)));
    redshift = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (10 - 0)));

    Galaxy galaxy(galaxy_type, total_mass, stellar_mass_fraction, redshift);
    galaxy.add_satellites();
    galaxy.print_stellar_mass();
    galaxy.print_galaxy_data();

    return 0;
}