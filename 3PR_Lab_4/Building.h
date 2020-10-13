#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Facade.h"

using namespace std;

class Building
{
private:
	// ����� ������� ���������.
	float sideLength;
	// ������ ����������.
	float basementHeight;
	// ������ �����.
	float floorHeight;
	// ���������� ������.
	int floorAmount;
	// ����������� ������������.
	float stabilityFactor;
	/* ������� �� ��������� ���������� �������� � �������� ���������� ������ Building. */
	void setBuiling(float b_sideLength, float b_basementHeight, float b_floorHeight, unsigned b_floorAmount, float b_stabilityFactor)
	{
		sideLength = b_sideLength;
		basementHeight = b_basementHeight;
		floorHeight = b_floorHeight;
		floorAmount = b_floorAmount;
		stabilityFactor = b_stabilityFactor;
	}
public:
	/* ������� �� ������ ������� ���������� ������ Building. */
	void getBuilding()
	{
		cout << "�������� ������� ������:" << endl;
		cout << "����� ������� ���������: " << sideLength << endl;
		cout << "������ ����������: " << basementHeight << endl;
		cout << "������ �����: " << floorHeight << endl;
		cout << "���������� ������: " << floorAmount << endl;
		cout << "����������� ������������: " << stabilityFactor << endl << endl;
	}
	/* ������� �� ������� ������� �� ��������� ���������� ������ Building. */
	void initBuilding()
	{
		setBuiling(1.0, 1.0, 1.0, 1, 1.0);
	}
	/* ������� �� ����� � ���������� ������� ��� ���������� ������ Building */
	void inputBuilding()
	{
		// ������ �� ������ ��� ����� ���� ����������� ������.
		cout << "������� ����� ������� ������ ������: ";
		while (!(cin >> sideLength) || cin.get() != '\n' || sideLength <= 0)
		{
			cout << "�������� ���� ����� ������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "������� ������ ���������� ������ ������: ";
		while (!(cin >> basementHeight) || cin.get() != '\n' || basementHeight <= 0)
		{
			cout << "�������� ���� ������ ���������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "������� ������ ������ ����� ������ ������: ";
		while (!(cin >> floorHeight) || cin.get() != '\n' || floorHeight <= 0)
		{
			cout << "�������� ���� ������ ����� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "������� ���������� ������ ������ ������: ";
		while (!(cin >> floorAmount) || cin.get() != '\n' || floorAmount <= 0)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ������������� ����� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}
		// ������ ����������� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		// ���� ����������� ������������ ������ 1 - ������ ������; ��������� ��������� ���� �������������
		if (stabilityFactor < 1.0)
		{
			cout << "����������� ������������ ������ ������ k = " << stabilityFactor << " ������ �������. ��� ����� ������� � ������ �� ������. ������ �� ����������� ���?" << endl;
			cout << "���� ��� - ������� Esc, ���� �� - ����� ������ ������." << endl << endl;
			if (_getch() != 27)
			{
				inputBuilding();
			}
			else
			{
				cout << "������ �� ������ ������� � �������!" << endl << endl << endl;
				initBuilding();
			}
		}
		else
		{
			cout << "�������! ������ ���������� ���������� � ������������� ������������ k = " << stabilityFactor << "." << endl << endl << endl;
		}
	}
	/* ������� �� �������� ���� ����������� ������ Building, ��� build - ���������, ������� ����� ������������. */
	void addToBuilding(Building build)
	{
		cout << "��������� ��� ������... �� �������� �����:" << endl;
		cout << "����� ������ ���������: " << sideLength << " � " << build.sideLength << endl <<
			"������ �����������: " << basementHeight << " � " << build.basementHeight << endl << "������ ������: " << floorHeight << " � " << build.floorHeight << endl <<
			"���������� ������: " << floorAmount << " � " << build.floorAmount << endl << "������������ ������������: " << stabilityFactor << " � " << build.stabilityFactor << endl << endl;

		if (sideLength < build.sideLength)
			sideLength = build.sideLength;

		if (basementHeight < build.basementHeight)
			basementHeight = build.basementHeight;

		if (floorHeight < build.floorHeight)
			floorHeight = build.floorHeight;

		floorAmount = floorAmount + build.floorAmount;
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1)
		{
			cout << "� ���������, ����� ���������� ���� ������ ����� ������ ����� �� �����������, ��� ��� ��� ����������� ������������ k = " << stabilityFactor << " ������ ����." << endl << endl;
			initBuilding();
		}
		else
		{
			cout << "�������! ����� ������ �������. ��� �������� �����:" << endl << endl;
			getBuilding();
		}
	}
	/* ������� �� ���������� floorsToAdd ������ ���������� ������ Building. */
	void addFloors()
	{
		unsigned floorsToAdd;
		// ������ �� ������ ��� ����� floorsToAdd.
		cout << "������� ���������� ������ ��� ���������� � ������ ������: ";
		while (!(cin >> floorsToAdd) || cin.get() != '\n' || floorsToAdd < 0)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ��������������� ����� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		floorAmount = floorAmount + floorsToAdd;
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1.0)
		{
			cout << "����������� ������������ ������ ������ k = " << stabilityFactor << " ���� ������ �������.\n��� ����� ������� � ������ �� ������. ���������� �������� ���������� ������ � ���������� (��������, �� 0)" << endl << endl;
			floorAmount = floorAmount - floorsToAdd;
			addFloors();
		}
		else
		{
			cout << "�������! ������ ���������� ���������� � ������������� ������������ k = " << stabilityFactor << endl << endl;
		}
		// ����������� ���������� � ������.
		getBuilding();
	}

	/* ������� �� �������� floorsToRemove ������ � ���������� ������ Building. */
	void removeFloors()
	{
		int floorsToRemove;
		// ������ �� ������ ��� ����� floorsToRemove.
		cout << "������� ���������� ������ ��� �������� � ������ ������: ";
		while (!(cin >> floorsToRemove) || cin.get() != '\n' || floorsToRemove < 0 || floorsToRemove >= floorAmount)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ��������������� ����� ������ � ������� ������ ����� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}
		// ������ ������ ������������ ������������.
		floorAmount = floorAmount - floorsToRemove;
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		cout << "����� ������� �������!" << endl;
		// ����������� ���������� � ������.
		getBuilding();
	}

};