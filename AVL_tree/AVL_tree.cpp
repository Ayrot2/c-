
#include <iostream>
using namespace std;

struct Node 
{
	int key; //значение
	Node* left; //правое поддерево
	Node* right; //левое поддерево
	int height; //высота узла
};


int height(Node* N) //нахождение высоты узла
{
	if (N == nullptr)
		return 0;
	return N->height;
}

Node* newNode(int key) //добавление нового узла с заданным ключом
{
	Node* node = new Node();
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1; //его высота равна 1
	return(node);
}

Node* rightRotate(Node* y) //правый поворот
{
	Node* x = y->left;
	Node* T2 = x->right;

	//совершаем поворот
	x->right = y;
	y->left = T2;

	//обновляем высоты узлов
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;
	return x;
}


Node* leftRotate(Node* x) //левый повторот
{
	Node* y = x->right;
	Node* T2 = y->left;

	//совершаем повторот
	y->left = x;
	x->right = T2;

	//обновляем высоты узлов
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}

int getBalance(Node* N) //возращает значение балансировки
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) //рекурсивная функция добавления элементов
{
	if (node == nullptr) //создаём новый узел, если не можем добавить элемент
		return(newNode(key));

	if (key < node->key) //поддерживаем структуру бинарного дерева
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // одинаковых элементов не предусмотрено
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right)); //обновляем высоты

	int balance = getBalance(node); //получаем значение балансировки


	//левый-левый случай
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// правый-правый случай
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// левый-правый случай
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// правый-левый случай
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void preOrder(Node* root) // распечатка дерева (по левой стороне) в глубину
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	Node* root = nullptr;

	int number, data;
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cin >> data;
		root = insert(root, data);
	}
	cout << "\n";
	preOrder(root);

	return 0;
}
