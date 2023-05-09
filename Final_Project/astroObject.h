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
    // std::string m_galaxy_type;
    double m_mass;
    // double m_stellar_mass_fraction;
    // double m_redshift;
    // std::vector<Galaxy> m_satellites;
public:
    Galaxy() {};
    Galaxy(const std::string& line);
    ~Galaxy() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Galaxy"; }
    std::string get_info() const override;
};

class Star : public AstroObject {
private:
    double m_mass;
    // double m_age;
    // double m_radius;
    // double m_temperature;

public:
    Star() {};
    Star(const std::string& line);
    virtual ~Star() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Star"; }
    std::string get_info() const override;
};

class Planet : public AstroObject {
private:
    double m_mass;
    // double m_radius;
    // double m_number_moons;
public:
    Planet() {};
    Planet(const std::string& line);
    ~Planet() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Planet"; }
    std::string get_info() const override;
};

class StellarNebula : public AstroObject {
private:
    double m_mass;
    // double m_radius;
    // std::vector<Star> m_stars;
public:
    StellarNebula() {};
    StellarNebula(const std::string& line);
    ~StellarNebula() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Stellar Nebula"; }
    std::string get_info() const override;
};

class SolarSystem : public AstroObject {
private:
    double m_age;
    // std::vector<Planet> planets;
    // std::vector<Star> stars;
public:
    SolarSystem() {};
    SolarSystem(const std::string& line);
    ~SolarSystem() {};

    void print_astro_info() const override;
    std::string get_type() override { return "Solar System"; }
    std::string get_info() const override;
};