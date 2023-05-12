#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>

const std::set<std::string> hubble_type {
    "E0", "E3", "E5", "E7", "S0", "Sa", "Sb", "Sc", "SBa", "SBb", "SBc", "Irr"
};

class AstroObject : public std::enable_shared_from_this<AstroObject>{
protected:
    std::string m_name;
    double m_ascension;
    double m_declination;
    double m_apparent_magnitude;
    double m_redshift;
    double m_distance_from_earth;
    std::vector<std::shared_ptr<AstroObject>> m_children;
    std::weak_ptr<AstroObject> m_parent;
    std::string m_parent_name;
public:
    ~AstroObject() { std::cout << "AstroObject destructor called for name: " << m_name << std::endl; };
    virtual std::string get_type() = 0;
    std::string get_astro_name() const { return m_name; }
    virtual void print_astro_info() const = 0;
    std::string get_parent_name() const { return m_parent_name; }
    void set_parent(std::shared_ptr<AstroObject> parent);
    void add_child(std::shared_ptr<AstroObject> child);
    std::weak_ptr<AstroObject> get_parent() const { return m_parent; }
    std::vector<std::shared_ptr<AstroObject>>& get_children() { return m_children; }
    void print_parent() const;
    void print_children() const;
    virtual std::string get_info() const = 0;
};

class Galaxy : public AstroObject {
private:
    std::string m_galaxy_type;
    double m_stellar_mass_fraction;
public:
    Galaxy() {};
    Galaxy(const std::string& line);
    Galaxy(std::string name, double ascension, double declination,
           double apparent_magnitude, double redshift, double distance_from_earth,
           std::string galaxy_type, double stellar_mass_fraction)
        : m_galaxy_type(galaxy_type), m_stellar_mass_fraction(stellar_mass_fraction)
    {
        m_name = name;
        m_ascension = ascension;
        m_declination = declination;
        m_apparent_magnitude = apparent_magnitude;
        m_redshift = redshift;
        m_distance_from_earth = distance_from_earth;
    }
    ~Galaxy() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Galaxy"; }
    std::string get_info() const override;
};

class Star : public AstroObject {
private:
    double m_mass;
    double m_radius;
    double m_temperature;
    double m_metalicity;

public:
    Star() {};
    Star(const std::string& line);
    Star(std::string name, double mass, double ascension, double declination,
           double apparent_magnitude, double redshift, double distance_from_earth,
           double radius, double temperature, double metalicity)
           : m_mass(mass), m_radius(radius), m_temperature(temperature), m_metalicity(metalicity)
    { 
        m_name = name; 
        m_ascension = ascension;
        m_declination = declination;
        m_apparent_magnitude = apparent_magnitude;
        m_redshift = redshift;
        m_distance_from_earth = distance_from_earth;
    };
    virtual ~Star() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Star"; }
    std::string get_info() const override;
};

class Planet : public AstroObject {
private:
    double m_mass;
    double m_radius;
    int m_number_moons;
    double m_orbital_period;
    double m_rotation_period;
    double m_orbital_eccentricity;
public:
    Planet() {};
    Planet(const std::string& line);
    Planet(std::string name, double mass, double ascension, double declination,
           double apparent_magnitude, double redshift, double distance_from_earth,
           double radius, double number_moons, double orbital_period, double rotation_period,
           double orbital_eccentricity)
           : m_mass(mass), m_radius(radius), m_number_moons(number_moons), m_orbital_period(orbital_period),
             m_rotation_period(rotation_period), m_orbital_eccentricity(orbital_eccentricity)
    { 
        m_name = name;
        m_ascension = ascension;
        m_declination = declination;
        m_apparent_magnitude = apparent_magnitude;
        m_redshift = redshift;
        m_distance_from_earth = distance_from_earth;
    };
    ~Planet() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Planet"; }
    std::string get_info() const override;
};

class StellarNebula : public AstroObject {
private:
    // double m_radius;
    // std::vector<Star> m_stars;
public:
    StellarNebula() {};
    StellarNebula(const std::string& line);
    StellarNebula(std::string name, double ascension, double declination,
           double apparent_magnitude, double redshift, double distance_from_earth)
    { 
        m_name = name;
        m_ascension = ascension;
        m_declination = declination;
        m_apparent_magnitude = apparent_magnitude;
        m_redshift = redshift;
        m_distance_from_earth = distance_from_earth;
    };
    ~StellarNebula() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Stellar Nebula"; }
    std::string get_info() const override;
};

class SolarSystem : public AstroObject {
private:
    // std::vector<Planet> planets;
    // std::vector<Star> stars;
public:
    SolarSystem() {};
    SolarSystem(const std::string& line);
    SolarSystem(std::string name, double ascension, double declination,
           double apparent_magnitude, double redshift, double distance_from_earth)
    { 
        m_name = name;
        m_ascension = ascension;
        m_declination = declination;
        m_apparent_magnitude = apparent_magnitude;
        m_redshift = redshift;
        m_distance_from_earth = distance_from_earth;
    };
    ~SolarSystem() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Solar System"; }
    std::string get_info() const override;
};