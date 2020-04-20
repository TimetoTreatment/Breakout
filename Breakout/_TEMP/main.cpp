#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<sf::Sound, 10> musics;

    sf::Music music;

    music.openFromFile("assets/sounds/sound.wav");

    music.play();


    system("pause");


    return 0;
}