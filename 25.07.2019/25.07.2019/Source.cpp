#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::exception;

class TreeExpression 
{

private:

	// Опис елемента дерева
	struct Node
	{
		char data;	// дані (символ операції або цифри)
		Node* left, *right;	// вказівники на нащадків
	};

	// Перечислення пріорітетів арифметичних операцій
	enum Priority { PLUS_MINUS, MULT_DIV, MAX_PR };

	// Рекурсивна функція створення дерева виразу
	// ex	 - арифметичний вираз
	// first - індекс початку виразу
	// last	 - індекс кінця виразу
	Node* CreateTree(string ex, int first, int last)
	{
		Node* tree = new Node;	// ствоерння нової вершини

		if (first == last)	// якщо це кінцева вершина: значення (операнд)
		{
			// записуємо дані та повертаємо вершину
			tree->data = ex[first];
			tree->left = nullptr;
			tree->right = nullptr;
			return tree;
		}

		// знаходимо операцію з найменшим пріорітетом
		int counter = 0;	// лічильний відкритих дужок
		int k = 0;			// індекс знайденої операції
		int minPr = MAX_PR;	// пріорітет знайденої операції

		for (int i = first; i <= last; ++i)	// цикл пошуку
		{

			if (ex[i] == '(') ++counter;		// відкрита дужка - збільшуємо лічильник
			else if (ex[i] == ')') --counter;	// закрита дужка - зменшуємо лічильник

			if ((!checkOperation(ex[i]) && !is_number(ex[i]) && ex[i] != '(' && ex[i] != ')') || is_space(ex[i])) {
				cout << ex[i] << endl;
				//cout << ex[i] << endl;
				throw exception("Invalid operation");
			}

			// якщо елемент не в дужках, враховуємо його
			if (counter == 0)
			{
				if (GetPriority(ex[i]) <= minPr)	// шукаємо останню операцію 
				{									// з найменшим пріорітетом
					minPr = GetPriority(ex[i]);
					k = i;
				}
			}
		}

		if (minPr == MAX_PR)	// якщо операцію не знайдено, 
		{						// це означає, що весь вираз взято в дужки						
			delete tree;								// звільняємо виділену пам'ять
			return CreateTree(ex, first + 1, last - 1);	// викликаємо ще раз функцію, відкинувши дужки
		}

		tree->data = ex[k];							// внутрішня вершина: операція
		tree->left = CreateTree(ex, first, k - 1);	// будуємо ліве піддерево на основі лівого підвиразу
		tree->right = CreateTree(ex, k + 1, last);	// будуємо праве піддерево на основі правого підвиразу

		return tree;	// повертаємо вершину
	}

	Node* tree;

public:

	TreeExpression(string ex) {
		tree = CreateTree(ex, 0, ex.length() - 1);	// будуємо дерево виразу
	}

	TreeExpression() {
		tree = nullptr;
	}

	Node* CreateTree(string ex)
	{
		int first = 0;
		int last = ex.length() - 1;

		tree = CreateTree(ex, 0, ex.length() - 1);
		
		return tree;	// повертаємо вершину
	}

	// Функція визначення пріорітету операції
	Priority GetPriority(char op)
	{
		switch (op)
		{
		case '-': case '+': return PLUS_MINUS;
		case '/': case '*': return MULT_DIV;
			// нам важливо визначити операцію з найменшим пріорітетом,
			// тому, якщо це не арифметична операція, повертаємо максимальний пріорітет
		default: return MAX_PR;
		}
	}

	// Обхід дерева: ЛПК
	void PrintLPK(Node* tree2)
	{
		if (tree2 == nullptr) return;

		PrintLPK(tree2->left);
		PrintLPK(tree2->right);
		cout << tree2->data << ' ';
	}

	// Обхід дерева: ЛПК
	void PrintLPK()
	{
		PrintLPK(tree->left);
		PrintLPK(tree->right);
		cout << tree->data << ' ';
	}

	// Обхід дерева: ЛКП
	void PrintLKP(Node* tree2)
	{
		if (tree2 == nullptr) return;

		PrintLKP(tree2->left);
		cout << tree2->data << ' ';
		PrintLKP(tree2->right);
	}

	// Обхід дерева: ЛКП
	void PrintLKP()
	{
		PrintLKP(tree->left);
		cout << tree->data << ' ';
		PrintLKP(tree->right);
	}

	// Рекурсивна функція обчислення виразу по дереву
	int CalcTree(Node* tree)
	{
		if (tree->left == nullptr)		// якщо немає нащадків - це значення
			return tree->data - '0';	// повертаємо цифру

		int left = CalcTree(tree->left);	// визначаємо значення лівого нащадка
		int right = CalcTree(tree->right);	// визначаємо значення правого нащадка

		switch (tree->data) // виконуємо операцію з визначеними операндами
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// якщо невірна операція - генеруємо виключну ситуацію
		default: throw exception("Invalid operation");
		}
	}

	// Валідація на дозволені операції
	bool checkOperation(char op) {

		return (op == '+' || op == '-' || op == '*' || op == '/');
	}

	// Валідація на число
	bool is_number(char ch)
	{
		return (int(ch) > 47 && int(ch) < 58);
	}

	// Валідація на space
	bool is_space(char space)
	{
		return (int(space) == 32);
	}

	// Рекурсивна функція обчислення виразу по дереву
	int CalcTree()
	{
		if (tree->left == nullptr)		// якщо немає нащадків - це значення
			return tree->data - '0';	// повертаємо цифру

		int left = CalcTree(tree->left);	// визначаємо значення лівого нащадка
		int right = CalcTree(tree->right);	// визначаємо значення правого нащадка

		switch (tree->data) // виконуємо операцію з визначеними операндами
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// якщо невірна операція - генеруємо виключну ситуацію
		default: throw exception("Invalid operation");
		}
	}

	// Рекурсивна функція обчислення виразу по дереву
	int CalcTree(string ex)
	{
		int first = 0;
		int last = ex.length() - 1;

		tree = CreateTree(ex, 0, ex.length() - 1);
		
		if (tree->left == nullptr)		// якщо немає нащадків - це значення
			return tree->data - '0';	// повертаємо цифру

		int left = CalcTree(tree->left);	// визначаємо значення лівого нащадка
		int right = CalcTree(tree->right);	// визначаємо значення правого нащадка

		switch (tree->data) // виконуємо операцію з визначеними операндами
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// якщо невірна операція - генеруємо виключну ситуацію
		default: throw exception("Invalid operation");
		}
	}
};

int main()
{

	/*
Завдання 2:
Написати методи валідації виразу. ,  та правильно розташовані дужки, також заборонено використовувати унарний мінус і плюс. Якщо алгоритм працює лише з одноцифровими числами, то і відповідна валідація.
Завдання 3:
Дозволити користувачу вводити пробільні символи в вираз, та унарні операції –/+.
Перед обчисленням пробільні символи потрібно відкидати, а унарні операції замінювати наступним чином:
–X = 0 – X
+X = X
*Завдання 4:
Удосконалити алгоритм так, щоб він мав змогу обчислювати вираз, який містить багатоцифрові числа (1 + 322 * (22 / 100)).

	*/
	string ex = "((0-1)+(6-3))*4/2"; // арифметичний вираз
	
	//TreeExpression tree(ex);
	TreeExpression tree2;     
	 
	try
	{
		tree2.CreateTree(ex);
	}
	catch (exception ex) // в разі помилки, обробляємо виключення
	{
		cout << ex.what() << endl;
	}
	
	TreeExpression tree = tree2;

	cout << "LPK: ";	// прохід дерева: ЛПК
	tree.PrintLPK();		// дозволяє визначити вираз
	cout << endl;		// за допомогою стека

	cout << "LKP: ";	// прохід дерева: ЛКП
	tree.PrintLKP();		// дозволяє подивитися початковий вигляд виразу 
	cout << endl;		// проте повністю відновити його не вийде - втрачаються дужки

	try
	{
		//int result = tree.CalcTree("((0-1)+(6-3))*4/2"); // обчислюємо вираз
		int result = tree.CalcTree(); // обчислюємо вираз по дереву
		cout << "Result: " << result << endl;
	}
	catch (exception ex) // в разі помилки, обробляємо виключення
	{
		cout << ex.what() << endl;
	}
	 
	system("pause");
	return 0;
}