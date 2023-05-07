#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <memory>

#include "astroObject.h"


class Section {
public:
    virtual ~Section() = default;
    virtual void add_object(std::unique_ptr<AstroObject> objPtr) = 0;
    virtual void print_all_objects() = 0;
    virtual std::vector<std::shared_ptr<AstroObject>> get_items() const = 0;
    virtual std::string get_section_name() const = 0;
};

class GalaxySection : public Section{
private:
    std::vector<std::unique_ptr<AstroObject>> m_galaxies;
public:
    GalaxySection() {};
    ~GalaxySection() {};

    std::vector<std::shared_ptr<AstroObject>> get_items() const;
    std::string get_section_name() const override { return "Galaxies"; };


    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        m_galaxies.push_back(std::move(objPtr));
    }
    void print_all_objects() override {
        for (auto& galaxy : m_galaxies) {
            galaxy->get_astro_name();
        }
    }
};

class NebulaSection : public Section{
private:
    std::vector<std::unique_ptr<AstroObject>> m_nebulae;
public:
    NebulaSection() {};
    ~NebulaSection() {};

    std::vector<std::shared_ptr<AstroObject>> get_items() const;
    std::string get_section_name() const override { return "Nebulae"; };

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        m_nebulae.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& nebula : m_nebulae) {
            nebula->get_astro_name();
        }
    }
};

class SolarSystemSection : public Section{
private:
    std::vector<std::unique_ptr<AstroObject>> m_solar_systems;
public:
    SolarSystemSection() {};
    ~SolarSystemSection() {};

    std::vector<std::shared_ptr<AstroObject>> get_items() const;
    std::string get_section_name() const override { return "Solar Systems"; };

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        m_solar_systems.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& solarSystem : m_solar_systems) {
            solarSystem->get_astro_name();
        }
    }
};

class StarSection : public Section{
private:
    std::vector<std::unique_ptr<AstroObject>> m_stars;
public:
    StarSection() {};
    ~StarSection() {};

    std::vector<std::shared_ptr<AstroObject>> get_items() const;
    std::string get_section_name() const override { return "Stars"; };

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        m_stars.push_back(std::move(objPtr));
    }


    void print_all_objects() override {
        for (auto& star : m_stars) {
            star->get_astro_name();
        }
    }
};

class PlanetSection : public Section{
private:
    std::vector<std::unique_ptr<AstroObject>> m_planets;
public:
    PlanetSection() {};
    ~PlanetSection() {};

    std::vector<std::shared_ptr<AstroObject>> get_items() const;
    std::string get_section_name() const override { return "Planets"; };

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        m_planets.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& planet : m_planets) {
            planet->get_astro_name();
        }
    }
};