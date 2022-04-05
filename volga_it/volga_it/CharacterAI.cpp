#include "fairy_tail.hpp"
#include "MapVisualizer.cpp"

class CharacterAI {

public:
	CharacterAI(MapVisualizer* map, bool* in_game, int* turn_count) {
		_map = map;
		_world = _map->GetMapWorld();
        _character = _map->GetMapCharacter();
        _character_in_game = in_game;
        _turn_count = turn_count;
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
    bool* _character_in_game;
    int* _turn_count;
    int character_coords[2];
    Direction past_directions[250];
    int directions_count = 0;

    Direction get_direction()
    {
        Direction my_direction = Direction::Pass;
        UpdateCharacterCoords();

        /*std::cout << "\n\t" << _map->GetCharInMap(character_coords[0] - 1, character_coords[1]) << '\n';
        std::cout << _map->GetCharInMap(character_coords[0], character_coords[1] - 1) << "\t\t";
        std::cout << _map->GetCharInMap(character_coords[0], character_coords[1] + 1) << '\n';
        std::cout << '\t' << _map->GetCharInMap(character_coords[0] + 1, character_coords[1]) << '\n';*/

        if (_map->GetCharInMap(character_coords[0], character_coords[1] - 1) == '.')
            my_direction = Direction::Left;
        else if (_map->GetCharInMap(character_coords[0], character_coords[1] + 1) == '.')
            my_direction = Direction::Right;
        else if (_map->GetCharInMap(character_coords[0] - 1, character_coords[1]) == '.')
            my_direction = Direction::Up;
        else if (_map->GetCharInMap(character_coords[0] + 1, character_coords[1]) == '.')
            my_direction = Direction::Down;
        else {
            //std::cout << "Where is no . on map\n";
            directions_count -= 1;
            my_direction = GetOppositeDirection(past_directions[directions_count]);
            if (directions_count <= 0) {
                //std::cout << "There is no possible solution!\n";
                *_turn_count = 0;
                *_character_in_game = false;
            }
            return my_direction;
        }
        past_directions[directions_count] = my_direction;
        directions_count++;
        return my_direction;
    }
    void WorldGoCharacter(Direction _dir) {

        switch (_character)
        {
        case Character::Ivan:
            if (_world->go(_dir, Direction::Pass)) {
                //std::cout << "Solution found in " << _world->getTurnCount() << "!\n";
                *_turn_count = _world->getTurnCount();
                *_character_in_game = false;
            }
            break;
        case Character::Elena:
            if (_world->go(Direction::Pass, _dir)) {
                //std::cout << "Solution found in " << _world->getTurnCount() << "!\n";
                *_turn_count = _world->getTurnCount();
                *_character_in_game = false;
            }
            break;
        default:
            break;
        }
    }
    void UpdateCharacterCoords() {
        character_coords[0] = _map->GetCharacterCoords()[0];
        character_coords[1] = _map->GetCharacterCoords()[1];
    }
    Direction GetOppositeDirection(Direction _direction) {
        Direction opposite_direction = Direction::Pass;
        switch (_direction)
        {
        case Direction::Up:
            opposite_direction = Direction::Down;
            break;
        case Direction::Down:
            opposite_direction = Direction::Up;
            break;
        case Direction::Left:
            opposite_direction = Direction::Right;
            break;
        case Direction::Right:
            opposite_direction = Direction::Left;
            break;
        default:
            break;
        }
        return opposite_direction;
    }
};