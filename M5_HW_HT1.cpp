#include <iostream>
#include "Windows.h"


class smart_array
{
private:
	int* arr;
	int* end;
	int fsize = 0;
	int lsize = 0;

public:
	smart_array(int setfsize) :fsize{ setfsize }
	{
		arr = new int[fsize];
	}

	void add_element(int elem)
	{
		if (lsize < fsize)
		{
			arr[lsize] = elem;
			lsize++;
		}
		else
		{
			fsize = fsize * 2;
			int* new_arr = new int[fsize];
			//fsize = fsize * 2;
			for (int i = 0; i < lsize; i++) new_arr[i] = arr[i];

			//std::cout << "lsize "<< lsize << std::endl;

			new_arr[lsize] = elem;

			lsize = lsize + 1;

			delete[] arr;

			arr = new_arr;
		}
	};

	~smart_array()
	{
		delete[] arr;
	};

	void print_arr()
	{
		std::cout << "Динамический массив: \n";
		for (int i = 0; i < fsize; i++)
		{
			if (i < lsize) std::cout << arr[i] << " ";
			else std::cout << "_ ";
		}
		std::cout << std::endl;
	}

	int get_element(int num)
	{
		return arr[num];
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int fsize = 5;
	try {
		smart_array arr(fsize);

		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		arr.add_element(55);
		arr.add_element(75);

		arr.add_element(88);
		arr.print_arr();
		std::cout << std::endl;
	
		std::cout <<"arr.get_element(1) " << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

