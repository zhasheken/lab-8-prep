#ifndef BASIC_TRANSFORM_H
#define BASIC_TRANSFORM_H
#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    sf::Vector2f scale;
    sf::Vector2f translation;

    BasicTransform(const sf::Vector2f& s = {1.f, 1.f}, const sf::Vector2f& t = {0.f, 0.f})
        : scale(s), translation(t) {}

    sf::Vector2f applyPoint(const sf::Vector2f& p) const {
        return sf::Vector2f(p.x * scale.x + translation.x, p.y * scale.y + translation.y);
    }

    sf::Vector2f applyVector(const sf::Vector2f& p) const {
        return sf::Vector2f(p.x * scale.x, p.y * scale.y);
    }

    bool operator==(const BasicTransform& other) const {
        return scale == other.scale && translation == other.translation;
    }
};

#endif  // BASIC_TRANSFORM_H
