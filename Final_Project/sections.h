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
    virtual void add_object(std::shared_ptr<AstroObject>& objPtr) = 0;
    virtual void print_all_objects() const = 0;
    virtual const std::vector<std::shared_ptr<AstroObject>>& get_items() const = 0;
    virtual std::string get_section_name() const = 0;
    int get_number_objects() const { return get_items().size(); };
    std::shared_ptr<AstroObject> get_object_at_index(int index) const { return get_items().at(index); };
    std::shared_ptr<AstroObject> get_object_by_name(const std::string& name) const {
        for (auto& obj : get_items()) {
            if (obj->get_astro_name() == name) {
                return obj;
            }
        }
        return nullptr;
    };
};

class GalaxySection : public Section{
private:
    std::vector<std::shared_ptr<AstroObject>> m_galaxies;
public:
    GalaxySection() {};
    ~GalaxySection() {};

    const std::vector<std::shared_ptr<AstroObject>>& get_items() const;
    std::string get_section_name() const override { return "Galaxies"; };


    void add_object(std::shared_ptr<AstroObject>& objPtr) override {
        m_galaxies.push_back(objPtr);
    }
    void print_all_objects() const override {
        for (auto& galaxy : m_galaxies) {
            std::cout << galaxy->get_astro_name() << std::endl;
        }
    }
};

class NebulaSection : public Section{
private:
    std::vector<std::shared_ptr<AstroObject>> m_nebulae;
public:
    NebulaSection() {};
    ~NebulaSection() {};

    const std::vector<std::shared_ptr<AstroObject>>& get_items() const;
    std::string get_section_name() const override { return "Nebulae"; };

    void add_object(std::shared_ptr<AstroObject>& objPtr) override {
        m_nebulae.push_back(objPtr);
    }

    void print_all_objects() const override {
        for (auto& nebula : m_nebulae) {
            std::cout << nebula->get_astro_name() << std::endl;
        }
    }
};

class SolarSystemSection : public Section{
private:
    std::vector<std::shared_ptr<AstroObject>> m_solar_systems;
public:
    SolarSystemSection() {};
    ~SolarSystemSection() {};

    const std::vector<std::shared_ptr<AstroObject>>& get_items() const;
    std::string get_section_name() const override { return "Solar Systems"; };

    void add_object(std::shared_ptr<AstroObject>& objPtr) override {
        m_solar_systems.push_back(objPtr);
    }

    void print_all_objects() const override {
        for (auto& solarSystem : m_solar_systems) {
            std::cout << solarSystem->get_astro_name() << std::endl;
        }
    }
};

class StarSection : public Section{
private:
    std::vector<std::shared_ptr<AstroObject>> m_stars;
public:
    StarSection() {};
    ~StarSection() {};

    const std::vector<std::shared_ptr<AstroObject>>& get_items() const;
    std::string get_section_name() const override { return "Stars"; };

    void add_object(std::shared_ptr<AstroObject>& objPtr) override {
        m_stars.push_back(objPtr);
    }


    void print_all_objects() const override {
        for (auto& star : m_stars) {
            std::cout << star->get_astro_name() << std::endl;
        }
    }
};

class PlanetSection : public Section{
private:
    std::vector<std::shared_ptr<AstroObject>> m_planets;
public:
    PlanetSection() {};
    ~PlanetSection() {};

    const std::vector<std::shared_ptr<AstroObject>>& get_items() const;
    std::string get_section_name() const override { return "Planets"; };

    void add_object(std::shared_ptr<AstroObject>& objPtr) override {
        m_planets.push_back(objPtr);
    }

    void print_all_objects() const override {
        for (auto& planet : m_planets) {
            std::cout << planet->get_astro_name() << std::endl;
        }
    }
};