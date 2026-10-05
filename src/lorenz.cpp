#include "lorenz.hpp"

void Lorenz::update(float dt) {

    float X1 = x + f(x, y) * dt;
    float Y1 = y + g(x, y, z) * dt;
    float Z1 = z + h(x, y, z) * dt;

    float X2 = x + f(x + X1 * 0.5f, y + Y1 * 0.5f) * dt;
    float Y2 = y + g(x + X1 * 0.5f, y + Y1 * 0.5f, z + Z1 * 0.5f) * dt;
    float Z2 = z + h(x + X1 * 0.5f, y + Y1 * 0.5f, z + Z1 * 0.5f) * dt;

    float X3 = x + f(x + X2 * 0.5f, y + Y2 * 0.5f) * dt;
    float Y3 = y + g(x + X2 * 0.5f, y + Y2 * 0.5f, z + Z2 * 0.5f) * dt;
    float Z3 = z + h(x + X2 * 0.5f, y + Y2 * 0.5f, z + Z2 * 0.5f) * dt;

    float X4 = x + f(x + X3, y + Y3) * dt;
    float Y4 = y + g(x + X3, y + Y3, z + Z3) * dt;
    float Z4 = z + h(x + X3, y + Y3, z + Z3) * dt;

    x = (X1 + 2.f * X2 + 2.f * X3 + X4) / 6.f;
    y = (Y1 + 2.f * Y2 + 2.f * Y3 + Y4) / 6.f;
    z = (Z1 + 2.f * Z2 + 2.f * Z3 + Z4) / 6.f;

}

void Lorenz::render(sf::RenderTexture *canvas) {

    sf::CircleShape s;
    s.setRadius(1);
    s.setFillColor(color);

    s.setPosition(sf::Vector2f((x * 16) + (WIDTH / 2), (y * 16) + (HEIGHT / 2)));

    canvas->draw(s);

}