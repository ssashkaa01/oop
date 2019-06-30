#pragma once
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

//#define Item int
//typedef int Item;
class Tree
{
private:
	struct Node
	{
		string data;
		List *offense;
		Node *left;
		Node *right;

		Node(string data, Node* left = nullptr, Node* right = nullptr, List* offense = nullptr)
			: data(data), left(left), right(right), offense(offense)
		{ }
	};

	Node * root;

	void Add(string data, Node*& node)
	{
		if (node == nullptr)
			node = new Node(data);

		else if (data > node->data)
			Add(data, node->right);
		else
			Add(data, node->left);
	}

	void PrintLKP(const Node* node, string data = "") const
	{
		if (node != nullptr)
		{
			if ((data != "" && node->data.substr(0, data.length()) == data) || data == "") 
			{
				cout << "-------------------\n";
				cout << "Number: " << node->data << endl;
				if (node->offense != nullptr) node->offense->ShowList();
				cout << "-------------------\n";
			}
			
			PrintLKP(node->left, data);
			PrintLKP(node->right, data);
		}
	}
	void PrintKLP(const Node* node, string data = "") const
	{
		if (node != nullptr)
		{
			if ((data != "" && node->data.substr(0, data.length()) == data) || data == "")
			{
				cout << "-------------------\n";
				cout << "Number: " << node->data << endl;
				if (node->offense != nullptr) node->offense->ShowList();
				cout << "-------------------\n";
			}
			PrintKLP(node->left);
			PrintKLP(node->right);
		}
	}
	void PrintPKL(const Node* node, string data = "") const
	{
		if (node != nullptr)
		{
			if ((data != "" && node->data.substr(0, data.length()) == data) || data == "")
			{
				cout << "-------------------\n";
				cout << "Number: " << node->data << endl;
				if (node->offense != nullptr) node->offense->ShowList();
				cout << "-------------------\n";
			}
			PrintPKL(node->right, data);
			PrintPKL(node->left, data);
		}
	}
	void PrintKPL(const Node* node, string data = "") const
	{
		if (node != nullptr)
		{
			if ((data != "" && node->data.substr(0, data.length()) == data) || data == "")
			{
				cout << "-------------------\n";
				cout << "Number: " << node->data << endl;
				if (node->offense != nullptr) node->offense->ShowList();
				cout << "-------------------\n";
			}
			PrintKPL(node->right, data);
			PrintKPL(node->left, data);
		}
	}

	bool Find(string data, const Node* node) const
	{
		if (node == nullptr) return false;

		if (node->data == data)
			return true;
		else if (data > node->data)
			return Find(data, node->right);
		else
			return Find(data, node->left);
	}
public:
	Tree()
	{
		root = nullptr;
	}

	bool AddOffense(string data, string _data)
	{
		for (Node * n = root; n != nullptr; /*вираз*/)
		{
			if (n->data == data) {

				if (n->offense == nullptr) {
					n->offense = new List();
				}
				n->offense->AddTail(_data);
				return true;
			}
			else if (data > n->data)
				n = n->right;
			else
				n = n->left;
		}
		return false;
	}

	void Add(string data)
	{
		Add(data, root);
	}
	void PrintLKP() const
	{
		PrintLKP(root);
	}
	void PrintKLP() const
	{
		PrintKLP(root);
	}
	void PrintPKL() const
	{
		PrintPKL(root);
	}
	void PrintKPL() const
	{
		PrintKPL(root);
	}

	void PrintSort(bool desc = false)
	{
		// умова ? вираз1 (true) : вираз2 (false); 
		desc ? PrintPKL() : PrintLKP();

		/*if (desc)
			PrintPKL();
		else
			PrintLKP();*/
	}

	bool Find(string data)
	{
		return Find(data, root);
	}
	bool FindLine(string data) const
	{
		for (Node * n = root; n != nullptr; /*вираз*/)
		{
			if (n->data == data) return true;
			else if (data > n->data)
				n = n->right;
			else
				n = n->left;
		}
		return false;
	}

	void PrintData(string data) const
	{
		for (Node * n = root; n != nullptr; /*вираз*/)
		{
			if (n->data == data) {
				cout << "-------------------\n";
				cout << "Number: " << n->data << endl;
				if(n->offense != nullptr) n->offense->ShowList();
				cout << "-------------------\n";
				return;
			}
			else if (data > n->data)
				n = n->right;
			else
				n = n->left;
		}
	}

	void PrintSortDiapazon(string diapazon, bool desc = false)
	{
		// умова ? вираз1 (true) : вираз2 (false); 
		desc ? PrintPKL(root, diapazon) : PrintLKP(root, diapazon);

		/*if (desc)
			PrintPKL();
		else
			PrintLKP();*/
	}
	
};