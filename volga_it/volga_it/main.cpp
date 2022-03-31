#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>

int walk()
{
    Fairyland world;

    for (int i = 0; i < 10000; ++i)
    {
        Direction direction;

        switch (rand() % 4)
        {
        case 0:
            direction = Direction::Up;
            break;

        case 1:
            direction = Direction::Down;
            break;

        case 2:
            direction = Direction::Left;
            break;

        default:
            direction = Direction::Right;
            break;
        }

        if (world.canGo(Character::Ivan, direction) && world.go(direction, Direction::Pass))
            return world.getTurnCount();
    }

    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    if (const int turns = walk())
        std::cout << "Found in " << turns << " turns" << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}
