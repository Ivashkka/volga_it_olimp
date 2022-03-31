#include "fairy_tail.hpp"
class MapVisualizer {

	public:

		MapVisualizer(Fairyland* world, Character character) {
			_world = world;
			_character = character;
			MapInit();
		}


		void UpdateMap() {
			//system("cls");
			mapCharList[character_coords[0]][character_coords[1]] = character_symbol;
			if (_world->canGo(_character, Direction::Left)) {
				if(mapCharList[character_coords[0]][character_coords[1] - 1] != '-')
					mapCharList[character_coords[0]][character_coords[1] - 1] = '.';
			}
			else mapCharList[character_coords[0]][character_coords[1] - 1] = '#';
			if (_world->canGo(_character, Direction::Right)) {
				if(mapCharList[character_coords[0]][character_coords[1] + 1] != '-')
					mapCharList[character_coords[0]][character_coords[1] + 1] = '.';
			}
			else mapCharList[character_coords[0]][character_coords[1] + 1] = '#';
			if (_world->canGo(_character, Direction::Up)) {
				if(mapCharList[character_coords[0] - 1][character_coords[1]] != '-')
					mapCharList[character_coords[0] - 1][character_coords[1]] = '.';
			}
			else mapCharList[character_coords[0] - 1][character_coords[1]] = '#';
			if (_world->canGo(_character, Direction::Down)) {
				if(mapCharList[character_coords[0] + 1][character_coords[1]] != '-')
					mapCharList[character_coords[0] + 1][character_coords[1]] = '.';
			}
			else mapCharList[character_coords[0] + 1][character_coords[1]] = '#';
			DrawMap();
		}


		void MoveCharacter(char axis) {
			Direction direction = Direction::Pass;
			mapCharList[character_coords[0]][character_coords[1]] = '-';
			switch (axis)
			{
			case 'a':
				if (_world->canGo(_character, Direction::Left)) {
					direction = Direction::Left;
					character_coords[1] -= 1;
				}
				//std::cout << "Left";
				break;
			case 'd':
				if (_world->canGo(_character, Direction::Right)) {
					direction = Direction::Right;
					character_coords[1] += 1;
				}
				//std::cout << "Right";
				break;
			case 'w':
				if (_world->canGo(_character, Direction::Up)) {
					direction = Direction::Up;
					character_coords[0] -= 1;
				}
				//std::cout << "Up";
				break;
			case 's':
				if (_world->canGo(_character, Direction::Down)) {
					direction = Direction::Down;
					character_coords[0] += 1;
				}
				//std::cout << "Down";
				break;
			default:
				break;
			}

			switch (_character)
			{
			case Character::Ivan:
				_world->go(direction, Direction::Pass);
				break;
			case Character::Elena:
				_world->go(Direction::Pass, direction);
				break;
			default:
				break;
			}
			UpdateMap();
		}


	private:
		Fairyland* _world;
		Character _character;
		static const int map_size = 21;
		int character_coords[2] = { map_size / 2, map_size / 2};
		char character_symbol;
		char mapCharList[map_size][map_size];


		void MapInit() {
			switch (_character)
			{
			case Character::Ivan:
				character_symbol = '@';
				break;
			case Character::Elena:
				character_symbol = '&';
				break;
			default:
				break;
			}
			for (int i = 0; i < map_size; i++)
			{
				for (int j = 0; j < map_size; j++)
				{
					mapCharList[i][j] = '?';
				}
			}
			mapCharList[character_coords[0]][character_coords[1]] = character_symbol;
		}


		void DrawMap() {
			for (int i = 0; i < map_size; i++)
			{
				for (int j = 0; j < map_size; j++)
				{
					std::cout << mapCharList[i][j];
				}
				std::cout << '\n';
			}
		}
};