#include <iostream>
using namespace std;

struct  Tree_Root // структура дерева
{
	int data; //значения
	Tree_Root* left; // левое поддерево
	Tree_Root* right; //правое поддерево
};

void show(Tree_Root*& Tree) //рекурсивная функция вывода на экран дерева, обход в глубину
{
	if (Tree != nullptr) //если узел не пустой
	{
		show(Tree->left); //обходим сначало самое левое поддерево
		cout << Tree->data;
		show(Tree->right); // затем его правые листья
	}
}

void del(Tree_Root*& Tree)
{
	if (Tree != nullptr)
	{
		del(Tree->left);
		del(Tree->right);
		delete Tree;
	}
}

void add_elements(int data, Tree_Root*& MyTree) //рекурсивная функция добавления элемента
{
	if (MyTree == nullptr) 
	{
		MyTree = new Tree_Root; //создаём новый узел
		MyTree->data = data; //записываем в него значение
		MyTree->left = nullptr; //левое поддерево пустое
		MyTree->right = nullptr; //правое поддерево пустое
	}
	else
	{
		if (data < MyTree->data) //поддерживаем структуру бинарного дерева
		{
			if (MyTree->left != nullptr) add_elements(data, MyTree->left); //рекурсивно добавляем элемент, если можем
			else //создаём новое поддерево, если не можем добавить
			{
				MyTree->left = new Tree_Root;
				MyTree->left->data = data;
				MyTree->left->left = nullptr;
				MyTree->left->right = nullptr;
			}
		}
		if (data >= MyTree->data) //поддерживаем структуру бинарного дерева
		{
			if (MyTree->right != nullptr) add_elements(data, MyTree->right); //рекурсивно добавляем элемент, если можем
			else //создаём новое поддерево, если не можем добавить
			{
				MyTree->right = new Tree_Root;
				MyTree->right->data = data;
				MyTree->right->left = nullptr;
				MyTree->right->right = nullptr;
			}
		}
	}
}

int main() {
	Tree_Root* Tree = nullptr; //корень
	int number;
	cin >> number;//количество элементов
	int data;
	for (int i = 0; i < number; i++) //циклически добавляем
	{
		cin >> data;
		add_elements(data, Tree);
	}
	show(Tree);
	del(Tree);
}