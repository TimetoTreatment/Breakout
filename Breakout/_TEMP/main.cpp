#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

    sf::Music music;

    music.openFromFile("assets/sounds/sound.wav");

    music.play();


    system("pause");


    return 0;
}