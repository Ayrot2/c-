#include <iostream>
using namespace std;

struct chess_f
{
	char column;
	int row = 0;
	int num_column = 0;
};

void output(int** figures)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << figures[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void input(int n, chess_f* figures1, int** figures, bool** b_figures)
{
	for (int i = 0; i < n; i++)
	{
		cin >> figures1[i].column >> figures1[i].row;
		switch (figures1[i].column)
		{
		case 'a':
			figures[8 - figures1[i].row][0] = 0;
			b_figures[8 - figures1[i].row][0] = true;
			figures1[i].num_column = 0;
			break;
		case 'b':
			figures[8 - figures1[i].row][1] = 0;
			b_figures[8 - figures1[i].row][1] = true;
			figures1[i].num_column = 1;
			break;
		case 'c':
			figures[8 - figures1[i].row][2] = 0;
			b_figures[8 - figures1[i].row][2] = true;
			figures1[i].num_column = 2;
			break;
		case 'd':
			figures[8 - figures1[i].row][3] = 0;
			b_figures[8 - figures1[i].row][3] = true;
			figures1[i].num_column = 3;
			break;
		case 'e':
			figures[8 - figures1[i].row][4] = 0;
			b_figures[8 - figures1[i].row][4] = true;
			figures1[i].num_column = 4;
			break;
		case 'f':
			figures[8 - figures1[i].row][5] = 0;
			b_figures[8 - figures1[i].row][5] = true;
			figures1[i].num_column = 5;
			break;
		case 'g':
			figures[8 - figures1[i].row][6] = 0;
			b_figures[8 - figures1[i].row][6] = true;
			figures1[i].num_column = 6;
			break;
		case 'h':
			figures[8 - figures1[i].row][7] = 0;
			b_figures[8 - figures1[i].row][7] = true;
			figures1[i].num_column = 7;
			break;
		}
	}
}

int dyn_solve(int n, chess_f* figures1, int** figures, bool** b_figures)
{
	int result = 0;
	figures[8 - figures1[n].row][figures1[n].num_column] = 1;
	output(figures);
	for (int i = 8 - figures1[n].row; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (figures[i][j] != -1)
			{
				if (i - 1 >= 0 && b_figures[i - 1][j] == false) figures[i - 1][j] += 2;
				if (i - 1 >= 0 && j - 1 >= 0 && b_figures[i - 1][j - 1] == true) figures[i - 1][j - 1] += 1;
				if (i - 1 >= 0 && j + 1 < 8 && b_figures[i - 1][j + 1] == true) figures[i - 1][j + 1] += 1;
				output(figures);
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		if (figures[0][i] != -1) result += figures[0][i];
	}
	return result;
}
int main()
{
	int n;
	cin >> n;
	chess_f* figures1 = new chess_f[n + 1];
	int** figures;
	bool** bool_figures;
	figures = new int* [64];
	bool_figures = new bool* [64];
	for (int i = 0; i < 8; i++)
	{
		figures[i] = new int[8];
		bool_figures[i] = new bool[8];
		for (int j = 0; j < 8; j++) {
			figures[i][j] = -1;
			bool_figures[i][j] = false;
		}
	}
	input(n + 1, figures1, figures, bool_figures);
	cout << dyn_solve(n, figures1, figures, bool_figures);
	return 0;
}