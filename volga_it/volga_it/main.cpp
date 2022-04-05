#include "fairy_tail.hpp"
#include "CharacterAI.cpp"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

Direction get_axis()
{
        Direction direction;

        switch (rand() % 4)
        {
        case 0:
            direction = Direction::Left;
            break;

        case 1:
            direction = Direction::Right;
            break;

        case 2:
            direction = Direction::Down;
            break;

        default:
            direction = Direction::Up;
            break;
        }
        return direction;

}

Direction GetCharDirection() {
    char axis;
    axis = _getch();
    switch (axis)
    {
    case 'a':
        return Direction::Left;
        break;
    case 'd':
        return Direction::Right;
        break;
    case 's':
        return Direction::Down;
        break;
    case 'w':
        return Direction::Up;
        break;
    default:
        break;
    }
}
std::string str_can_go(Character _check_character, Direction _check_dir, Fairyland* _land) {
    if (_land->canGo(_check_character, _check_dir)) return "CAN";
    else return "CANT";
}

int main()
{
    Fairyland world;
    
    MapVisualizer mapIvan(&world, Character::Ivan);
    MapVisualizer mapElena(&world, Character::Elena);

    bool in_game = true;
    int turn_count = 0;
    CharacterAI IvanAI(&mapIvan, &in_game, &turn_count);
    CharacterAI ElenaAI(&mapElena, &in_game, &turn_count);

    mapIvan.UpdateMap();
    std::cout << "\n\n";
    mapElena.UpdateMap();
    char manual_axis;

    while (in_game)
    {

        //manual_axis = _getch();
        system("cls");
        //IvanAI.ManualTurn(manual_axis);
        mapIvan.PrintMapInfo();
        IvanAI.doTurn();
        //std::cout << "\t" << str_can_go(Character::Ivan, Direction::Up, &world) << '\n';
        //std::cout << str_can_go(Character::Ivan, Direction::Left, &world) 
        //    << "\t\t" << str_can_go(Character::Ivan, Direction::Right, &world) << '\n';
        //std::cout << "\t" << str_can_go(Character::Ivan, Direction::Down, &world) << '\n';
        //std::cout << "\n";
        //mapElena.PrintMapInfo();
        //ElenaAI.doTurn();

        Sleep(100);
    }
    system("cls");
    std::cout << "Final map:\n";
    mapIvan.PrintFinalMap();
    switch (turn_count)
    {
    case 0:
        std::cout << "\nThere is no possible solution!\n";
    default:
        std::cout << "\nSolution found in " << turn_count << "!\n";;
    }
    /*srand(static_cast<unsigned int>(time(nullptr)));

    if (const int turns = walk())
        std::cout << "Found in " << turns << " turns" << std::endl;
    else
        std::cout << "Not found" << std::endl;*/

    return 0;
}
