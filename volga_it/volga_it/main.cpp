#include "fairy_tail.hpp"
#include "CharacterAI.cpp"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main()
{
    Fairyland world; // create world
    
    MapVisualizer mapIvan(&world, Character::Ivan); // create map with Character (also can be Elena)

    bool in_game = true; // if our Character still moving cross the map
    int turn_count = 0;
    CharacterAI IvanAI(&mapIvan, &in_game, &turn_count); // create Ivan Character AI

    mapIvan.UpdateMap(); // First drawing Character's map

    while (in_game) // main cycle
    {

        system("cls"); //clear console
        mapIvan.PrintMapInfo(); // print info about current map
        IvanAI.doTurn(); // Character's AI moves the character
        Sleep(10); // turn delay
    }
    system("cls");
    std::cout << "Final map:\n"; // print final map view
    mapIvan.PrintFinalMap();
    switch (turn_count) // Print turn_count if we found the way
    {
    case 0:
        std::cout << "\nThere is no possible solution!\n";
    default:
        std::cout << "\nSolution found in " << turn_count << "!\n";;
    }

    return 0;
}