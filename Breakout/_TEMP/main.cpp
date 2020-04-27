#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <array>
#include <SFML/System.hpp>

using namespace std;

int main()
{
    string asdf = "¡ê  ¡ê  ¡ê  ¡ê  ¡ê  ";

    cout << asdf << endl;

    for (int i = 1; i < 10; i++)
    {
        asdf.pop_back();
        asdf.pop_back();

        cout << i << " : " << asdf << endl;

    }






    return 0;
}