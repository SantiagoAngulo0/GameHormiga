//
// Created by santi on 5/6/2025.
//

#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Ray {
private:
    int puntosLuz;
    int semillas;
    float probCritico;
    std::vector<std::string> equipamientos;
    std::string nombre;
    int vitalidad;
    int vidas;
    int alimento;
    std::vector<std::string> habilidades;
    std::vector<std::string> poderesEspeciales;

    sf::Sprite sprite;
    sf::Texture textureDerecha;
    sf::Texture textureIzquierda;
    float velocidad = 5.0f;
    float velocidadSalto = 12.0f;
    float gravedad = 0.8f;
    float velocidadY = 0;
    bool enSuelo = false;
    bool isMooving = false;
    float alturaSprite;
    float sueloY;

    sf::Vector2f posicion;
    sf::Texture textureCaminata;
    int currentFrame = 0;
    float frameDuration = 0.1f;
    float animationTimer = 0.0f;
    int totalFrames = 4;
    sf::Vector2i frameSize = { 225, 320 };


public:
    Ray(const std::string& nombre, int vitalidad, int vidas, const std::string& texturePath);

    void cambiarEstadoMascara(int nuevaVitalidad);
    void golpearBaston();
    void superGolpeLuz();
    void recargarLuz();
    void recolectarSemilla();
    void moverDerecha();
    void moverIzquierda();
    void moverAbajo(float deltaTime);
    void saltar();
    void recibirDano(int dano);
    void usarPoderEspecial(const std::string& nombrePoder);
    void setPosicion(const sf::Vector2f& posicion);
    void setSueloY(float sueloY);


    void actualizar(float deltaTime);
    void Updateanimacion(float deltaTime);
    void dibujar(sf::RenderWindow& ventana) const;
    sf::FloatRect obtenerLimites() const;

};

#endif // RAY_H


