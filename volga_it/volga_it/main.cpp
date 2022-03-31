#include "fairy_tail.hpp"
#include "MapVisualizer.cpp"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

char get_axis()
{
        char direction;

        switch (rand() % 4)
        {
        case 0:
            direction = 'a';
            break;

        case 1:
            direction = 'd';
            break;

        case 2:
            direction = 's';
            break;

        default:
            direction = 'w';
            break;
        }
        return direction;

}

int main()
{
    Fairyland world;
    MapVisualizer map2(&world, Character::Ivan);
    MapVisualizer map(&world, Character::Elena);

    map2.UpdateMap();
    
    char axis;

    while (true)
    {

        //Sleep(500);
        axis = _getch();
        system("cls");
        /*axis = get_axis();
        map.MoveCharacter(axis);
        std::cout << "\n\n";
        axis = get_axis();*/

        map2.MoveCharacter(axis);


    }
    /*srand(static_cast<unsigned int>(time(nullptr)));

    if (const int turns = walk())
        std::cout << "Found in " << turns << " turns" << std::endl;
    else
        std::cout << "Not found" << std::endl;*/

    return 0;
}
