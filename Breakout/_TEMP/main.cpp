#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int main()
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Assets/sounds/sound.wav"))
        return -1;



    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    sound.setLoop(true);

    sf::Clock clock;

    


    for (int i = 1; i < 50; i++)
    {
        sound.setVolume(i);

        for (;clock.getElapsedTime() <= sf::milliseconds(150);)
            ;



        printf("%d\n", clock.getElapsedTime().asMilliseconds());

        clock.restart();
    }





    system("pause");
    return 0;
}