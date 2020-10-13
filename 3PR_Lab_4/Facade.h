#pragma once
#include <iostream>
using namespace std;

class Facade
{
private:
	int windowsAmount;
	int openedWindowsAmount;
public:
	void setFacade(int windowsAmount, int openedWindowsAmount)
	{
		this->windowsAmount = windowsAmount;
		this->openedWindowsAmount = openedWindowsAmount;
	}

	int getWindowsAmount()
	{
		return windowsAmount;
	}

	int getOpenedWindowsAmount()
	{
		return openedWindowsAmount;
	}

	void getFacade()
	{
		cout << "Общее количество окон: " << windowsAmount << endl;
		cout << "Количество открытых окон: " << openedWindowsAmount << endl;
	}

	void inputFacade()
	{
		cout << "Введите общее количество окон вашего здания: ";
		while (!(cin >> windowsAmount) || cin.get() != '\n' || windowsAmount < 0)
		{
			cout << "Неверный ввод количества окон - оно должно быть целым неотрицательным числом. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "Введите количество открытых окон вашего здания: ";
		while (!(cin >> openedWindowsAmount) || cin.get() != '\n' || openedWindowsAmount < 0 || openedWindowsAmount > windowsAmount)
		{
			cout << "Неверный ввод количества открытых окон - оно должно быть не меньше нуля и не больше общего числа окон. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}
	}

	void openWindows()
	{
		int windowsToOpen;
		cout << "Введите количество окон, которые вы хотите открыть: ";
		while (!(cin >> windowsToOpen) || cin.get() != '\n' || windowsToOpen < 0 || windowsToOpen > (windowsAmount - openedWindowsAmount))
		{
			cout << "Неверный ввод количества окон для открытия - оно должно быть не меньше нуля и не больше возможного для открытия числа окон. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		openedWindowsAmount += windowsToOpen;
	}

	void closeWindows()
	{
		int windowsToClose;
		cout << "Введите количество окон, которые вы хотите закрыть: ";
		while (!(cin >> windowsToClose) || cin.get() != '\n' || windowsToClose < 0 || windowsToClose > openedWindowsAmount)
		{
			cout << "Неверный ввод количества окон для закрытия - оно должно быть не меньше нуля и не больше числа открытых окон. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		openedWindowsAmount -= windowsToClose;
	}

	void addToFacade(Facade facadeToAdd)
	{
		windowsAmount += facadeToAdd.windowsAmount;
		openedWindowsAmount += facadeToAdd.openedWindowsAmount;
	}
};

