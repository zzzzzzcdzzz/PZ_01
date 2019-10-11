

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void FahrenheitCelsius(float temperature = 32, char CF = 'C');
void ArithmeticMean(int sizeArray = 10, char autoForArray = 'y');
void UniqueArray(int sizeArray = 20);

void AppOne(float& temperature, char& tempChar);
void AppThree(int& sizeArray);
void AppTwo(int& sizeArray, char& tempChar);
void bContinue(char& tempChar, bool& bcontinue);


int main()
{
	srand(time(NULL));

	float a = 0.0f; // temp variable for float to integer
	int App = 0;
	float temperature = 0;
	char tempChar = ' ';
	int sizeArray;
	bool bcontinue = true;

	// Menu

	do
	{
		std::cout << "PZ_01" << std::endl;
		std::cout << "1 - for conversion Fahrenheit to Celsius or Celsius to Fahrenheit." << std::endl;
		std::cout << "2 - for arithmetic mean." << std::endl;
		std::cout << "3 - for unique array." << std::endl;

		do
		{
			std::cout << "Enter number (1, 2, 3): ";
			std::cin >> a;

			if (a <= 0 || a > 3)
			{
				std::cout << "Error input. You need to enter number 1 or 2 or 3." << std::endl << std::endl;
			}
		} while (a <= 0 || a > 3);

		App = a; // float to integer

		switch (App)
		{
			case 1:
			AppOne(temperature, tempChar);
			break;

			case 2:
			AppTwo(sizeArray, tempChar);
			break;

			case 3:
			AppThree(sizeArray);
			break;

			default:
			break;
		}

		bContinue(tempChar, bcontinue);
	} while (!bcontinue);

	return 0;
}

void FahrenheitCelsius(float temperature, char CF)
{
	float temp;

	if (CF == 'C' || CF == 'c')
	{
		temp = (temperature * 1.8f) + 32; // °F = (°C * 1.8) + 32
		std::cout << std::endl << temperature << " C = " << temp << " F" << std::endl;
	}

	if (CF == 'F' || CF == 'f')
	{
		temp = (temperature - 32) / 1.8f; // °C = (°F - 32) / 1.8
		std::cout << std::endl << temperature << " F = " << temp << " C" << std::endl;
	}
}

void ArithmeticMean(int sizeArray, char autoForArray)
{
	if (sizeArray < 0)
	{
		sizeArray = -sizeArray;
	}

	int* arr = new int[sizeArray];
	int arithmeticMean = 0;

	std::cout << std::endl;

	if (autoForArray == 'N' || autoForArray == 'n')
	{
		int temp = 0;

		for (int i = 0; i < sizeArray; ++i)
		{
			std::cout << "Enter a value for array[" << i << "]: ";
			std::cin >> temp;
			arr[i] = temp;
		}
	}
	else
	{
		for (int i = 0; i < sizeArray; ++i)
		{
			arr[i] = rand() % 10 + 1;
			std::cout << "The value array[" << i << "]: " << arr[i] << std::endl;
		}
	}

	for (int i = 0; i < sizeArray; ++i)
	{
		arithmeticMean += arr[i];
	}

	std::cout << "The Arithmetic mean your array = " << (arithmeticMean / sizeArray) << " or as float " << (arithmeticMean / (float)sizeArray) << std::endl;
	delete[]arr;
}

void UniqueArray(int sizeArray)
{
	if (sizeArray < 0)
	{
		sizeArray = -sizeArray;
	}

	int* arr = new int[sizeArray];

	for (int i = 0; i < sizeArray; ++i)
	{
		arr[i] = rand() % 5 + 1;
		std::cout << "The value of array[" << i << "] = " << arr[i] << std::endl;
	}

	std::vector<int> vec(arr, arr + sizeArray);
	std::vector<int>::iterator iter;

	sort(vec.begin(), vec.end());
	iter = unique(vec.begin(), vec.end());
	vec.resize(iter - vec.begin());

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << "[" << vec[i] << "] ";
	}

	std::cout << std::endl;

	delete[] arr;
}

void AppOne(float& temperature, char& tempChar)
{
	std::cout << "Enter a temperature (number) and a temperature scale (C/F): ";
	std::cin >> temperature >> tempChar;

	while (tempChar != 'C' && tempChar != 'F' && tempChar != 'c' && tempChar != 'f')
	{
		std::cout << "ERROR. Enter a temperature (number) and a temperature scale (C/F): ";
		std::cin >> temperature >> tempChar;
	}

	FahrenheitCelsius(temperature, tempChar);
}

void AppTwo(int& sizeArray, char& tempChar)
{
	std::cout << "Enter a size Array (number) and auto (y/n): ";
	std::cin >> sizeArray >> tempChar;

	while (tempChar != 'Y' && tempChar != 'N' && tempChar != 'y' && tempChar != 'n')
	{
		std::cout << "ERROR. Enter a size Array (number) and auto (y/n): ";
		std::cin >> sizeArray >> tempChar;
	}

	ArithmeticMean(sizeArray, tempChar);
}

void AppThree(int& sizeArray)

{
	std::cout << std::endl << "Enter a size Array (number): ";
	std::cin >> sizeArray;

	UniqueArray(sizeArray);
}

void bContinue(char& tempChar, bool& bcontinue)
{
	std::cout << std::endl;
	std::cout << "Continue? (y/n): ";
	std::cin >> tempChar;
	std::cout << std::endl;

	if (tempChar != 'Y' && tempChar != 'y')
	{
		bcontinue = true;
	}
	else
	{
		bcontinue = false;
	}
}
