#include "pch.h"
#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void buble_sort(int *array, int array_size, unsigned int start_time)
{
	int i = 0;
	int buffer;
	char swap = 0;

	if (array_size == 0)
		cout << "Нечего сортировать\n";

	while (i < array_size)
	{
		if (i + 1 != array_size && array[i] > array[i + 1])
		{
			buffer = array[i];
			array[i] = array[i + 1];
			array[i + 1] = buffer;
			swap = 1;
		}
		i++;
		if(i == array_size && swap == 1)
		{
			swap = 0;
			i = 0;
		}
	}

	/*for (int i = 0; i < array_size; i++)
	{
		cout<<" "<< array[i] ;
	}*/

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout<<"Время работы проги, cек: "<< search_time/1000;
};

int main()
{
	setlocale(LC_ALL, "");

	unsigned int start_time = clock();
	
	int num = 0;

	cout << "Введите необходимый размер массива\n";

	cin >> num;

	int *p_darr = new int[num]; 

	srand(time(0));

	for (int i = 0; i < num; i++) 
	{
		
		p_darr[i] =rand()% 100000;

		//cout << "Value of " << i << " element is " << p_darr[i] << endl;
	}

	buble_sort(p_darr, num, start_time);
	
	delete[] p_darr;

	return 0;
}


