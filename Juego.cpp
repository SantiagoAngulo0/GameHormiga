//
// Created by santi on 5/8/2025.
//

#include "Juego.h"

Juego::Juego() :
    ventana(sf::VideoMode(1800, 900), "Mi Juego"),
    jugador("Protagonista", 100, 3, "assets"),
//cambiar la ruta de abajo por donde tenga el archivo
    puertaEscenario("C:/Users/ASUS ROG/Documents/tareas Universidad/POO/GameHormiga-main/puerta_sprite.png", sf::Vector2f(1000, 500)),
    currentEscenario("escenario1"){

    cambiarEscenario("escenario1");
    fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        jugador.moverDerecha();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        jugador.moverIzquierda();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        jugador.saltar();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        cout << sf::Mouse::isButtonPressed(sf::Mouse::Left) << endl;
    }

}

void Juego::actualizar(float deltaTime) {
    jugador.actualizar(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        jugador.moverAbajo(deltaTime);
    }
    VerificarColisiones();
}

void Juego::dibujar() {
    ventana.clear();
    ventana.draw(fondo);
    puertaEscenario.dibujar(ventana);
    jugador.dibujar(ventana);
    ventana.display();
}

void Juego::cambiarEscenario(const string& nombreEscenario) {
    if (nombreEscenario == "escenario1") {
        if (!texFondo.loadFromFile("C:/Users/ASUS ROG/Documents/tareas Universidad/POO/GameHormiga-main/cmake-build-debug/Tilest 1.PNG")) {
            cout << "Erro ao abrir texture fondo" << endl;
        }
        fondo.setTexture(texFondo);
        puertaEscenario.setPosition(Vector2f(1300, 200));
        fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
    }
    else if (nombreEscenario == "escenario2") {
        if (!texFondo.loadFromFile("C:/Users/ASUS ROG/Documents/tareas Universidad/POO/GameHormiga-main/escenario2.png")) {
            cout << "Erro ao abrir texture fondo" << endl;
        }
        fondo.setTexture(texFondo);
        puertaEscenario.setPosition(Vector2f(1000, 200));
        fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
    }
    fondo.setTexture(texFondo);
    currentEscenario = nombreEscenario;
}

void Juego::VerificarColisiones() {
    if (jugador.obtenerLimites().intersects(puertaEscenario.getBounds())) {
        if (currentEscenario == "escenario1") {
            cambiarEscenario("escenario2");
            puertaEscenario.setPosition(Vector2f(1000, 200));
        }
        else {
            cambiarEscenario("escenario1");
            puertaEscenario.setPosition(Vector2f(1300, 200));
        }
        jugador.setPosicion(Vector2f(100, 200));
    }
}
