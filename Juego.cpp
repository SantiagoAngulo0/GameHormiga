//
// Created by santi on 5/8/2025.
//

#include "Juego.h"

Juego::Juego() :
    ventana(sf::VideoMode(1200, 625), "Mi Juego"),
    jugador("Protagonista", 100, 3, "assets") {

    texFondo.loadFromFile("Tilest 1.PNG"); // Usa el nombre exacto del archivo
    fondo.setTexture(texFondo);
    fondo.setScale(1200.0f / texFondo.getSize().x, 1400.0f / texFondo.getSize().y);
}

void Juego::iniciar() {
    sf::Clock reloj;
    while (ventana.isOpen()) {
        float deltaTime = reloj.restart().asSeconds();
        procesarEventos();
        actualizar(deltaTime);
        dibujar();
    }
}

void Juego::procesarEventos() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        jugador.moverDerecha();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        jugador.moverIzquierda();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        jugador.saltar();
    }
}

void Juego::actualizar(float deltaTime) {
    jugador.actualizar(deltaTime);
}

void Juego::dibujar() {
    ventana.clear();
    ventana.draw(fondo);
    jugador.dibujar(ventana);
    ventana.display();
}
