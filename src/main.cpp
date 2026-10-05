#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "global.hpp"
#include "lorenz.hpp"

int main() {

    std::cout << std::endl;

    // ========== //

    sf::Clock clock;
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WIDTH, HEIGHT}),
        "lorenz-system", 
        sf::Style::Default, 
        sf::State::Windowed,
        settings
    );
    window.setVerticalSyncEnabled(false);

    sf::RenderTexture canvas({WIDTH, HEIGHT});
    canvas.clear(sf::Color(20, 20, 20));
    canvas.display();

    const sf::Font font("fonts/Consolas.ttf");

    sf::Text fpsText(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color(255, 255, 255, 100));
    fpsText.setPosition({10, 10});

    sf::Text deltaTimeText(font);
    deltaTimeText.setCharacterSize(20);
    deltaTimeText.setFillColor(sf::Color(255, 255, 255, 100));
    deltaTimeText.setPosition({10, 30});

    Lorenz L1(
        10, 28, 8/3,
        0.9, 0, 0,
        sf::Color::White
    );

    Lorenz L2(
        10, 28, 8/3,
        1, 0, 0,
        sf::Color::Red
    );

    Lorenz L3(
        10, 28, 8/3,
        1.1, 0, 0,
        sf::Color::Blue
    );

    int frameCounter = 0;
    const int updateEvery = 72;

    while (window.isOpen()) {

        float df = clock.restart().asSeconds();

        frameCounter++;
        if (frameCounter >= updateEvery) {

            frameCounter = 0;

            std::ostringstream ss;
            ss << "fps: " << std::fixed << std::setprecision(0) << 1 / df;
            fpsText.setString(ss.str());

            ss.str("");
            ss.clear();

            ss << "dt: " << std::fixed << std::setprecision(4) << dt << " fixed physics step";
            deltaTimeText.setString(ss.str());

        }

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();

        }

        L1.update(dt);
        // L2.update(dt);
        // L3.update(dt);

        window.clear(sf::Color(20, 20, 20));

            L1.render(&canvas);
            // L2.render(&canvas);
            // L3.render(&canvas);

            canvas.display();
            sf::Sprite canvasSprite(canvas.getTexture());
            
            window.draw(canvasSprite);
            window.draw(fpsText);
            window.draw(deltaTimeText);

        window.display();
    }

    // ========== //

    std::cout << std::endl;
    return 0;

}