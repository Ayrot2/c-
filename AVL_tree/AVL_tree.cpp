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


struct Queue // Структура очереди
{
	int size; // Размер очереди
	unsigned capacity; // Вместимость очереди
	Node** array;
};

Queue* createQueue(unsigned capacity) // Создание очереди заданной вместимости
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->size = 0;
	queue->array = new Node*[queue->capacity];
	return queue;
}

int isFull(Queue* queue) // Проверка на заполненность очереди
{
	return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) // Проверка на пустоту очереди
{
	return (queue->size == 0);
}

void push(Queue* queue, Node* item) // Добавление в конец
{
	if (isFull(queue))
		return;
	if (item != nullptr)
	{
		queue->array[queue->size+1] = item;
		queue->size = queue->size + 1;
	}
}


void Wight(Queue* q, int capacity) // распечатка дерева в ширину.
{
	if (!isEmpty(q)) // Если очередь пустая, то мы обошли всё дерево
	{
		for (int i = 0; i < q->size; i++) // Цикл вывода на экран узлов дерева
		{
			cout << q->array[i]->key << " ";
		}
		int cap = q->size * 2; // Вспомогательная переменная, равная вместимости (максимальному
		//размеру) следующего уровня
		Queue* q1 = createQueue(cap); // Создаём очередь следующего уровня
		int fiks = 0; // Вспомогательная переменная. Счётчик вырожденных случаев
		for (int i = 0; i < q1->capacity; i += 2) // Цикл заполения очереди следующего уровня
		{
			push(q1, q->array[i / 2]->left);
			push(q1, q->array[i / 2]->right);
			if (q->array[i / 2]->left == nullptr) fiks += 1;
			if (q->array[i / 2]->right == nullptr) fiks += 1;
			if (q->array[i / 2]->left != nullptr) // Логическая конструкция, предупреждающая
				//все вырожденные случаи
			{
				q1->array[i - fiks] = q->array[i / 2]->left;
				if (q->array[i / 2]->right != nullptr) q1->array[i + 1 - fiks] = q->array[i / 2]->right;
			}
			else
			{
				if (q->array[i / 2]->right != nullptr) q1->array[i + 1 - fiks] = q->array[i / 2]->right;
			}

		}
		cout << "\n";
		delete[] q; // Удаление очереди предыдущего уровня
		Wight(q1, cap); // Рекурсивно вызываем функцию для следующего уровня
	}
	else
	{
		return;
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
	Queue* q = createQueue(1);
	push(q, root);
	if (root != nullptr) 
	{
		q->array[0] = root;
		q->array[0]->key = root->key;
		Wight(q, 1);
	}
	return 0;
}
