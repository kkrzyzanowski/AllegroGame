#include "Player.h"

Player::Player()
{
    points = 0;
    setName("Karol");
}

Player::~Player()
{
    //dtor
}
int Player::getPoints()
{
    return points;
}
void Player::addPoints()
{
    points+=10;
}
string Player::getName()
{
    return name;
}
void Player::setName(string n)
{
    name = n;
}
void Player::clearPoints()
{
    points = 0;
}
