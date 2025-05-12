//
// Created by santi on 5/6/2025.
//
#include "Ray.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Ray::Ray(const std::string& nombre, int vitalidad, int vidas, const std::string& texturePath)
    : nombre(nombre), vitalidad(vitalidad), vidas(vidas) {

    // Cargar texturas
    if (!textureDerecha.loadFromFile("Hormida derecha.PNG") ||
        !textureIzquierda.loadFromFile("hormiga izquierda.png")) {
        std::cerr << "Error cargando texturas de Ray\n";
        }

    // Usar textura por defecto
    sprite.setTexture(textureDerecha);

    // Escalar el sprite
    sprite.setScale(0.3f, 0.3f);

    // Obtener altura del sprite y altura del suelo
    alturaSprite = sprite.getGlobalBounds().height;
    sueloY = 300.0f; // Ajusta este valor si el personaje flota o se entierra

    // Posición inicial
    posicion = sf::Vector2f(100, sueloY - alturaSprite);
    sprite.setPosition(posicion);

    // Física
    velocidad = 1.0f;
    velocidadSalto = 17.0f;
    gravedad = 1.0f;
    velocidadY = 0.0f;
    enSuelo = true;
}

void Ray::actualizar(float deltaTime) {
    velocidadY += gravedad;
    posicion.y += velocidadY;

    if (posicion.y >= sueloY - alturaSprite) {
        posicion.y = sueloY - alturaSprite;
        velocidadY = 0;
        enSuelo = true;
    }

    sprite.setPosition(posicion);
}

void Ray::moverDerecha() {
    posicion.x += velocidad;
    sprite.setTexture(textureDerecha);
}

void Ray::moverIzquierda() {
    posicion.x -= velocidad;
    sprite.setTexture(textureIzquierda);
}

void Ray::saltar() {
    if (enSuelo) {
        velocidadY = -velocidadSalto;
        enSuelo = false;
    }
}

void Ray::moverAbajo(float deltaTime) {
    if (!enSuelo) {
        float velocidadCaida = velocidadSalto * 1.5f;
        posicion.y += velocidadCaida * deltaTime;
        sprite.setPosition(posicion);

        // Debug
        std::cout << "Moviendo abajo. Pos Y: " << posicion.y
                  << " | En suelo: " << enSuelo << std::endl;
    }
}



void Ray::dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(sprite);
}

sf::FloatRect Ray::obtenerLimites() const {
    return sprite.getGlobalBounds();
}

void Ray::setPosicion(const sf::Vector2f& posicion) {
    this -> posicion = posicion;
}