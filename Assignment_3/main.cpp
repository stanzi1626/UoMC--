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

double random_double(double min, double max)
{
    return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
}

class Galaxy {
private:
    hubble_type galaxy_type;
    double total_mass;
    double stellar_mass_fraction;
    double redshift;
    std::vector<Galaxy> satellites;

public:
    Galaxy() {}

    Galaxy(hubble_type galaxy_type, double total_mass, double stellar_mass_fraction, double redshift)
    : galaxy_type(galaxy_type), total_mass(total_mass), stellar_mass_fraction(stellar_mass_fraction), redshift(redshift)
    {}

    ~Galaxy() {}

    void print_stellar_mass()
    {
        std::cout << "Stellar mass: " << pow(10, total_mass) * stellar_mass_fraction << " solar masses" << std::endl;
    }

    Galaxy create_random_satellite(){
        hubble_type galaxy_type;
        double total_mass;
        double stellar_mass_fraction;
        double redshift;

        galaxy_type = static_cast<hubble_type>(rand() % 12);
        total_mass = random_double(7, 12);
        stellar_mass_fraction = random_double(0, 0.05);
        redshift = random_double(0, 10);

        Galaxy galaxy(galaxy_type, total_mass, stellar_mass_fraction, redshift);
        return galaxy;
    }

    void add_satellites()
    {
        for (int i = 0; i < rand() % 10; i++) {
            satellites.push_back(create_random_satellite());
        }
    }

    void print_all_galaxies()
    {
        std::cout << "##########################" << std::endl;
        std::cout << "Main Galaxy" << std::endl;
        std::cout << "##########################" << std::endl;
        print_stellar_mass();
        print_galaxy_data();
        if (satellites.size() != 0) {
            std::cout << "##########################" << std::endl;
            std::cout << "Satellites" << std::endl;
            std::cout << "##########################" << std::endl;
        }
        for (auto itr = satellites.begin(); itr != satellites.end(); ++itr) {
            itr -> print_galaxy_data();
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
    total_mass = random_double(7, 12);
    stellar_mass_fraction = random_double(0, 0.05);
    redshift = random_double(0, 10);

    Galaxy galaxy(galaxy_type, total_mass, stellar_mass_fraction, redshift);
    galaxy.add_satellites();
    galaxy.print_all_galaxies();

    std::cout << std::endl << "##########################" << std::endl;
    std::cout << "Changing main galaxy type to E0" << std::endl;
    galaxy.change_galaxy_type(hubble_type::E0);
    galaxy.print_galaxy_data();

    return 0;
}