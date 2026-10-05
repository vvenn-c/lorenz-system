#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

#include "global.hpp"

class Lorenz {

    private:
    
        float sigma, rho, beta;
        float x, y, z;

        float f(float x, float y) { return sigma * (y - x); }
        float g(float x, float y, float z) { return x * (rho - z) - y; }
        float h(float x, float y, float z) { return x * y - beta * z; }

        sf::Color color;

    public:

        Lorenz(float s, float r, float b, float x, float y, float z, sf::Color color)
         : sigma(s), rho(r), beta(b), x(x), y(y), z(z), color(color) {}

        void update(float dt);
        void render(sf::RenderTexture *canvas);

};