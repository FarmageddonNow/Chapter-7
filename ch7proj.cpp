#include <iostream>
#include <conio.h>

int char2int(char& input);
void ace(int& aces, int& sum);
int q8();

int main()
{
	int pounds, days, repeat = 1;
	
	while (repeat == 1)
	{
		int f1 = 1, f2 = 1, f3 = 1; // By setting f3 initial value at 1, not running the loop does nothing.

		std::cout << "How many pounds of green crud do we have initially?" << std::endl;
		std::cin >> pounds;

		std::cout << "How many days do we let it grow?" << std::endl;
		std::cin >> days;		

		for (int iterations = (days/5) - 2; iterations >= 0; iterations--)
		{
			f3 = f1 + f2;

			f1 = f2;
			f2 = f3;
		}

		pounds = f3*pounds;
		std::cout << "There will be " << pounds << " pounds of green crud after " << days << " days." << std::endl;

		std::cout << "Enter '1' to repeat. Otherwise, enter any other number." << std::endl;
		std::cin >> repeat;
	}
	_getch();
	return 0;
}

int q8()
{
	char value;
	int n, aces = 0, sum = 0;

	std::cout << "How many cards do you have?" << std::endl;
	std::cin >> n;

	for (int x = 0; x < n; x++)
	{
		std::cout << "Enter the number value of card you have. For ten use the letter 't'. For face cards, use letters." << std::endl;
		std::cin >> value;
		if ((value == 'a') || (value == 'A'))
		{
			aces++;
		}
		else
		{
			sum = sum + char2int(value); // 'aces' and 'sum' need to be put elsewhere if want to count another hand
		}		
	}
	
	ace(aces, sum);

	std::cout << "Your hand is at " << sum << "." << std::endl;
	
	if (sum > 21)
	{
		std::cout << "BUSTED!" << std::endl;
	}

	_getch();
	return 0;
}

int char2int(char& input)
{
	switch(input)
	{
	case '2':
		return 2;  // No need to use 'break' if you straight up give a return
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 't':
	case 'T':
	case 'j':
	case 'J':
	case 'q':
	case 'Q':
	case 'k':
	case 'K':
		return 10;
	default:
		return 0;
	}
}

void ace(int& aces, int& sum)
{
	sum = sum + aces;
	
	if ((10 + sum) <= 21)
	{
		sum = sum + 10;
	}
	// Originally had a for loop, but realized that you can only turn an ace into an 11 once in a hand ever
}