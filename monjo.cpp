#include "utils.hpp"

Monjo::Monjo(sf::Sprite sprite) {
    this.sprite = sprite;
    this.lvlConc = 0;
    this.pos.x = 0;
    this.pos.y = 0;
}


void Monjo::setSprite(sf::Sprite sprite) {
    this.sprite = sprite;
}

sf::Sprite Monjo::getSprite() {
    return this.sprite;
}


sf::Vector2i Monjo::getPos() {
    return this.pos;
}

void Monjo::upLvlConc() {
    this.lvlConc += 5;
}

void Monjo::downLvlConc(bool b) {
    if (b) this.lvlConc -= 5;
    else this.lvlConc -= 2;
}
