#pragma once
class Facade
{
private:
	int windowsAmount;
	int openedWindowsAmount;

	void setFacade(int windowsAmount, int openedWindowsAmount)
	{
		this->windowsAmount = windowsAmount;
		this->openedWindowsAmount = openedWindowsAmount;
	}
public:
	void getFacade()
	{
		cout << "����� ���������� ����: " << windowsAmount << endl;
		cout << "���������� �������� ����: " << openedWindowsAmount << endl << endl;
	}
};

