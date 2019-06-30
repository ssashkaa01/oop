#include "Tree.h"
#include <iostream>
using namespace std;

void main()
{
	/*
	Завдання.
Реалізувати базу даних ДАІ по штрафним квитанціям за допомогою бінарного дерева.
Ключем служитиме номер автомашини, значенням вузла - список правопорушень. Якщо квитанція додається в перший раз,
то в дереві з'являється новий вузол, та список "дані про правопорушення" куди записуємо квитанцію, якщо ні, то дані заносяться в існуючий список.

Необхідно також реалізувати наступні операції:
 - Повна роздруківка бази даних (за номерами машин і списку правопорушень, що значаться за ними);
 - Роздруківка даних по заданому номеру;
 - Роздруківка даних за діапазоном номерів.
	*/
	Tree tree;

	//ADD NUMBERS TO DATABASE
	tree.Add("AB3435BB");
	tree.Add("BK3266OO");
	tree.Add("AB5430BR");

	//ADD OFFENSE
	tree.AddOffense("BK3266OO", "Very big speed");

	//PRINT DATA
	tree.PrintData("BK3266OO");

	//PRINT ALL DATABASE
	tree.PrintSort();
	
	//PRINT DIAPAZON
	tree.PrintSortDiapazon("AB");

	system("pause");
}