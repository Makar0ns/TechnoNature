#include "MyForm.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;

struct Tile
{
	double x;
	double y;
	char structure;
	bool unit;
	char status;
};
Tile map[200];

void create_map(int size)
{
	double start_x = 0, start_y=0, current_x=0, current_y=0;
	const int side = 10;
	map[0].x = 0;
	map[0].y = 0;
	int sign = 1;
	for (int j = 0; j < size; j++)
	{
		current_x = start_x;
		current_y = start_y;
		for (int i = 1; i <= size; i++)
		{
			
			if (sign > 0)
			{
				map[i+j*10].x = current_x + side * sqrt(3) / 2;
			}
			else map[i+j*10].x = current_x - side * sqrt(3) / 2;
			//std::cout << sign << ' ' << map[i * j].x << "\n";
			current_x = map[i+j*10].x;
			sign = -sign;
			map[i+j*10].y = current_y - side * 1.5;
			current_y = map[i+j*10].y;
		}
		start_x += side * sqrt(3);
		sign = 1;
		start_y = 0;
	}

}
int main(array<String^>^ args)
{
	//Application::SetCompatibleTextRenderingDefault(false);
	//Application::EnableVisualStyles();
	//TechnoNature::MyForm MyForm;
	//Application::Run(% MyForm);
	int size=17;
	//std::cin >> size;
	create_map(size);
	//for (int k = 0; k <= size * size; k++)
	//{
	//	std::cout << map[k].x << ' ' << map[k].y<<'\n';
	//}
	return 0;
}
