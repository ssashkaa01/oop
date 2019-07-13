#pragma once
#include <iostream>
using std::cout; using std::endl;

namespace TreeSpace {
	//#define Item int
	//typedef int Item;
	class Tree
	{
	private:
		struct Node
		{
			int data;
			Node *left;
			Node *right;

			Node(int data, Node* left = nullptr, Node* right = nullptr)
				: data(data), left(left), right(right)
			{ }
		};

		Node * root;

		void Add(int data, Node*& node)
		{
			if (node == nullptr)
				node = new Node(data);

			else if (data > node->data)
				Add(data, node->right);
			else
				Add(data, node->left);
		}

		void PrintLKP(const Node* node) const
		{
			if (node != nullptr)
			{
				PrintLKP(node->left);
				cout << node->data << endl;
				PrintLKP(node->right);
			}
		}
		void PrintKLP(const Node* node) const
		{
			if (node != nullptr)
			{
				cout << node->data << endl;
				PrintKLP(node->left);
				PrintKLP(node->right);
			}
		}
		void PrintPKL(const Node* node) const
		{
			if (node != nullptr)
			{
				PrintPKL(node->right);
				cout << node->data << endl;
				PrintPKL(node->left);
			}
		}
		void PrintKPL(const Node* node) const
		{
			if (node != nullptr)
			{
				cout << node->data << endl;
				PrintKPL(node->right);
				PrintKPL(node->left);
			}
		}

		bool Find(int data, const Node* node) const
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

		void Add(int data)
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

		bool Find(int data)
		{
			return Find(data, root);
		}
		bool FindLine(int data) const
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
	};
}