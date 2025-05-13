//
// Created by santi on 5/8/2025.
//

#include "Juego.h"

Juego::Juego() :
    ventana(sf::VideoMode(1800, 900), "Mi Juego"),
    jugador("Protagonista", 100, 3, "assets"),
//cambiar la ruta de abajo por donde tenga el archivo
    puertaEscenario("C:/Users/s4m976/Downloads/GameHormiga/puerta_sprite.png", sf::Vector2f(1396, 285)),
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
        if (!texFondo.loadFromFile("C:/Users/s4m976/Downloads/GameHormiga/cmake-build-debug/Tilest 1.PNG")) {
            cout << "Erro ao abrir texture fondo" << endl;
        }
        jugador.setSueloY(500);
        fondo.setTexture(texFondo);
        puertaEscenario.setPosition(Vector2f(1396, 285));
        fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
        jugador.setPosicion(Vector2f(60, 785));

    }
    else if (nombreEscenario == "escenario2") {
        if (!texFondo.loadFromFile("C:/Users/s4m976/Downloads/GameHormiga/escenario2.png")) {
            cout << "Erro ao abrir texture fondo" << endl;
        }
        fondo.setTexture(texFondo);
        puertaEscenario.setPosition(Vector2f(100, 660));
        fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
        jugador.setSueloY(800);
        jugador.setPosicion(Vector2f(1300, 800));

    }
    else if (nombreEscenario == "escenario3") {
        if (!texFondo.loadFromFile("C:/Users/s4m976/Downloads/GameHormiga/escenario3.png")) {
            cout << "Erro ao abrir texture fondo" << endl;
        }
        fondo.setTexture(texFondo);
        puertaEscenario.setPosition(Vector2f(1300, 560));
        jugador.setSueloY(800);
        fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
        jugador.setPosicion(Vector2f(100, 860));
    }
    else if (nombreEscenario == "escenario4") {
        if (!texFondo.loadFromFile("C:/Users/s4m976/Downloads/GameHormiga/escenario4.png")) {
            cout << "Erro ao abrir texture fondo" << endl;
        }
        fondo.setTexture(texFondo);
        puertaEscenario.setPosition(Vector2f(300, 560));
        jugador.setSueloY(800);
        fondo.setScale(ventana.getSize().x / fondo.getLocalBounds().width, ventana.getSize().y/fondo.getLocalBounds().height);
        jugador.setPosicion(Vector2f(1000, 860));
    }
    fondo.setTexture(texFondo);
    currentEscenario = nombreEscenario;
}

void Juego::VerificarColisiones() {
    if (jugador.obtenerLimites().intersects(puertaEscenario.getBounds())) {
        if (currentEscenario == "escenario1") {
            cambiarEscenario("escenario2");
        }
        else if (currentEscenario == "escenario2") {
            cambiarEscenario("escenario3");
        }
        else if (currentEscenario == "escenario3") {
            cambiarEscenario("escenario4");
        }
        else {
            cambiarEscenario("escenario1");
        }


    }
}
