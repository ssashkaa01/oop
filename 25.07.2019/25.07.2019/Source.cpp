#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::exception;

class TreeExpression 
{

private:

	// ���� �������� ������
	struct Node
	{
		char data;	// ��� (������ �������� ��� �����)
		Node* left, *right;	// ��������� �� �������
	};

	// ������������ �������� ������������ ��������
	enum Priority { PLUS_MINUS, MULT_DIV, MAX_PR };

	// ���������� ������� ��������� ������ ������
	// ex	 - ������������ �����
	// first - ������ ������� ������
	// last	 - ������ ���� ������
	Node* CreateTree(string ex, int first, int last)
	{
		Node* tree = new Node;	// ��������� ���� �������

		if (first == last)	// ���� �� ������ �������: �������� (�������)
		{
			// �������� ��� �� ��������� �������
			tree->data = ex[first];
			tree->left = nullptr;
			tree->right = nullptr;
			return tree;
		}

		// ��������� �������� � ��������� ���������
		int counter = 0;	// �������� �������� �����
		int k = 0;			// ������ �������� ��������
		int minPr = MAX_PR;	// ������� �������� ��������

		for (int i = first; i <= last; ++i)	// ���� ������
		{

			if (ex[i] == '(') ++counter;		// ������� ����� - �������� ��������
			else if (ex[i] == ')') --counter;	// ������� ����� - �������� ��������

			if ((!checkOperation(ex[i]) && !is_number(ex[i]) && ex[i] != '(' && ex[i] != ')') || is_space(ex[i])) {
				cout << ex[i] << endl;
				//cout << ex[i] << endl;
				throw exception("Invalid operation");
			}

			// ���� ������� �� � ������, ��������� ����
			if (counter == 0)
			{
				if (GetPriority(ex[i]) <= minPr)	// ������ ������� �������� 
				{									// � ��������� ���������
					minPr = GetPriority(ex[i]);
					k = i;
				}
			}
		}

		if (minPr == MAX_PR)	// ���� �������� �� ��������, 
		{						// �� ������, �� ���� ����� ����� � �����						
			delete tree;								// ��������� ������� ���'���
			return CreateTree(ex, first + 1, last - 1);	// ��������� �� ��� �������, ��������� �����
		}

		tree->data = ex[k];							// �������� �������: ��������
		tree->left = CreateTree(ex, first, k - 1);	// ������ ��� �������� �� ����� ����� ��������
		tree->right = CreateTree(ex, k + 1, last);	// ������ ����� �������� �� ����� ������� ��������

		return tree;	// ��������� �������
	}

	Node* tree;

public:

	TreeExpression(string ex) {
		tree = CreateTree(ex, 0, ex.length() - 1);	// ������ ������ ������
	}

	TreeExpression() {
		tree = nullptr;
	}

	Node* CreateTree(string ex)
	{
		int first = 0;
		int last = ex.length() - 1;

		tree = CreateTree(ex, 0, ex.length() - 1);
		
		return tree;	// ��������� �������
	}

	// ������� ���������� �������� ��������
	Priority GetPriority(char op)
	{
		switch (op)
		{
		case '-': case '+': return PLUS_MINUS;
		case '/': case '*': return MULT_DIV;
			// ��� ������� ��������� �������� � ��������� ���������,
			// ����, ���� �� �� ����������� ��������, ��������� ������������ �������
		default: return MAX_PR;
		}
	}

	// ����� ������: ���
	void PrintLPK(Node* tree2)
	{
		if (tree2 == nullptr) return;

		PrintLPK(tree2->left);
		PrintLPK(tree2->right);
		cout << tree2->data << ' ';
	}

	// ����� ������: ���
	void PrintLPK()
	{
		PrintLPK(tree->left);
		PrintLPK(tree->right);
		cout << tree->data << ' ';
	}

	// ����� ������: ���
	void PrintLKP(Node* tree2)
	{
		if (tree2 == nullptr) return;

		PrintLKP(tree2->left);
		cout << tree2->data << ' ';
		PrintLKP(tree2->right);
	}

	// ����� ������: ���
	void PrintLKP()
	{
		PrintLKP(tree->left);
		cout << tree->data << ' ';
		PrintLKP(tree->right);
	}

	// ���������� ������� ���������� ������ �� ������
	int CalcTree(Node* tree)
	{
		if (tree->left == nullptr)		// ���� ���� ������� - �� ��������
			return tree->data - '0';	// ��������� �����

		int left = CalcTree(tree->left);	// ��������� �������� ����� �������
		int right = CalcTree(tree->right);	// ��������� �������� ������� �������

		switch (tree->data) // �������� �������� � ����������� ����������
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// ���� ������ �������� - �������� �������� ��������
		default: throw exception("Invalid operation");
		}
	}

	// �������� �� �������� ��������
	bool checkOperation(char op) {

		return (op == '+' || op == '-' || op == '*' || op == '/');
	}

	// �������� �� �����
	bool is_number(char ch)
	{
		return (int(ch) > 47 && int(ch) < 58);
	}

	// �������� �� space
	bool is_space(char space)
	{
		return (int(space) == 32);
	}

	// ���������� ������� ���������� ������ �� ������
	int CalcTree()
	{
		if (tree->left == nullptr)		// ���� ���� ������� - �� ��������
			return tree->data - '0';	// ��������� �����

		int left = CalcTree(tree->left);	// ��������� �������� ����� �������
		int right = CalcTree(tree->right);	// ��������� �������� ������� �������

		switch (tree->data) // �������� �������� � ����������� ����������
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// ���� ������ �������� - �������� �������� ��������
		default: throw exception("Invalid operation");
		}
	}

	// ���������� ������� ���������� ������ �� ������
	int CalcTree(string ex)
	{
		int first = 0;
		int last = ex.length() - 1;

		tree = CreateTree(ex, 0, ex.length() - 1);
		
		if (tree->left == nullptr)		// ���� ���� ������� - �� ��������
			return tree->data - '0';	// ��������� �����

		int left = CalcTree(tree->left);	// ��������� �������� ����� �������
		int right = CalcTree(tree->right);	// ��������� �������� ������� �������

		switch (tree->data) // �������� �������� � ����������� ����������
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// ���� ������ �������� - �������� �������� ��������
		default: throw exception("Invalid operation");
		}
	}
};

int main()
{

	/*
�������� 2:
�������� ������ �������� ������. ,  �� ��������� ���������� �����, ����� ���������� ��������������� ������� ���� � ����. ���� �������� ������ ���� � ������������� �������, �� � �������� ��������.
�������� 3:
��������� ����������� ������� ������� ������� � �����, �� ����� �������� �/+.
����� ����������� ������� ������� ������� ��������, � ����� �������� ��������� ��������� �����:
�X = 0 � X
+X = X
*�������� 4:
������������ �������� ���, ��� �� ��� ����� ����������� �����, ���� ������ ������������ ����� (1 + 322 * (22 / 100)).

	*/
	string ex = "((0-1)+(6-3))*4/2"; // ������������ �����
	
	//TreeExpression tree(ex);
	TreeExpression tree2;     
	 
	try
	{
		tree2.CreateTree(ex);
	}
	catch (exception ex) // � ��� �������, ���������� ����������
	{
		cout << ex.what() << endl;
	}
	
	TreeExpression tree = tree2;

	cout << "LPK: ";	// ������ ������: ���
	tree.PrintLPK();		// �������� ��������� �����
	cout << endl;		// �� ��������� �����

	cout << "LKP: ";	// ������ ������: ���
	tree.PrintLKP();		// �������� ���������� ���������� ������ ������ 
	cout << endl;		// ����� ������� �������� ���� �� ����� - ����������� �����

	try
	{
		//int result = tree.CalcTree("((0-1)+(6-3))*4/2"); // ���������� �����
		int result = tree.CalcTree(); // ���������� ����� �� ������
		cout << "Result: " << result << endl;
	}
	catch (exception ex) // � ��� �������, ���������� ����������
	{
		cout << ex.what() << endl;
	}
	 
	system("pause");
	return 0;
}