#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "astroObject.h"

class AverageStar : Star
{
private:
    std::vector<Planet> planets;
};

class RedGiant : Star
{
private:
    std::vector<Planet> planets;
};

class WhiteDwarf : Star
{
private:
    std::vector<Planet> planets;
};

class MassiveStar : Star
{
private:
    std::vector<Planet> planets;
};

class RedSupergiant : Star
{
private:
    std::vector<Planet> planets;
};

class BlackHole : Star
{
};