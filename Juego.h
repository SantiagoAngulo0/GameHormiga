//
// Created by santi on 5/8/2025.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "Ray.h"


class Juego {
private:
    std::vector<sf::Sprite> escenarios;
    Ray jugador;
    std::map<std::string, int> top10;

    sf::RenderWindow ventana;
    sf::Clock reloj;
    sf::Sprite fondo;
    sf::Texture texFondo;

public:
    Juego();

    void iniciar();
    void iniciarEscenario(const std::string& nombreEscenario);
    void procesarInput();
    void procesarEventos();
    void actualizar(float deltaTime);
    void dibujar();
    void finalizarJuego();
    void guardarTop10();
    void cargarTop10();
    void mostrarTop10();
    bool cargarTextura(sf::Texture& textura, const std::string& ruta);
};
