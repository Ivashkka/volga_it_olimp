#include "fairy_tail.hpp"
#include "MapVisualizer.cpp"

class CharacterAI {

public:
	CharacterAI(MapVisualizer* map) {
		_map = map;
		_world = _map->GetMapWorld();
        _character = _map->GetMapCharacter();
	}
	void doTurn() {
        Direction dir;
        dir = get_direction();
        if (_world->canGo(_character, dir)) {
            WorldGoCharacter(dir);
            _map->MoveCharacter(dir);
        }
        else
        {
            _map->UpdateMap();
        }
	}
    void ManualTurn(char axis) {
        Direction manual_dir = Direction::Pass;
        switch (axis)
        {
        case 'a':
            manual_dir = Direction::Left;
            break;
        case 'd':
            manual_dir = Direction::Right;
            break;
        case 's':
            manual_dir = Direction::Down;
            break;
        case 'w':
            manual_dir = Direction::Up;
            break;
        default:
            break;
        }
        if (_world->canGo(_character, manual_dir)) {
            WorldGoCharacter(manual_dir);
            _map->MoveCharacter(manual_dir);
        }
        else
        {
            _map->UpdateMap();
        }
    }


private:
	Fairyland* _world;
	MapVisualizer* _map;
    Character _character;
    Direction get_direction()
    {
        switch (rand() % 4)
        {
        case 0:
            return Direction::Left;
            break;

        case 1:
            return Direction::Right;
            break;

        case 2:
            return Direction::Down;
            break;

        default:
            return Direction::Up;
            break;
        }
    }
    void WorldGoCharacter(Direction _dir) {
        switch (_character)
        {
        case Character::Ivan:
            _world->go(_dir, Direction::Pass);
            break;
        case Character::Elena:
            _world->go(Direction::Pass, _dir);
            break;
        default:
            break;
        }
    }
};