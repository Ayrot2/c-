#include <iostream>
using namespace std;

void input(int* seq, int len)
{
    for (int i = 0; i < len; i++)
    {
        cin >> seq[i];
    }
}


int dynamic_solve(int* seq1, int* seq2, int len1, int len2, int** mem)
{
    if (0 == len1 || 0 == len2)
    {
        if (mem[len1][len2] == 0) mem[len1][len2] = 1;
        return mem[len1][len2];
    }
    if (seq1[len1 - 1] == seq2[len2 - 1])
    {
        if (0 == mem[len1 - 1][len2 - 1]) {
            mem[len1 - 1][len2 - 1] =
                dynamic_solve(seq1, seq2, len1 - 1, len2 - 1, mem);
        }
        return mem[len1 - 1][len2 - 1] + 1;
    }
    if (0 == mem[len1 - 1][len2]) {
        mem[len1 - 1][len2] =
            dynamic_solve(seq1, seq2, len1 - 1, len2, mem);
    }
    if (0 == mem[len1][len2 - 1]) {
        mem[len1][len2 - 1] =
            dynamic_solve(seq1, seq2, len1, len2 - 1, mem);
    }
    return max(mem[len1 - 1][len2], mem[len1][len2 - 1]);
}

int main()
{
    int len1, len2;
    cin >> len1 >> len2;
    int* seq1 = new int[len1];
    int* seq2 = new int[len2];
    input(seq1, len1);
    input(seq2, len2);
    int** memoization;
    memoization = new int* [len1 + 1];
    for (int i = 0; i < len1 + 1; i++)
    {
        memoization[i] = new int[len2 + 1];
    }
    for (int i = 0; i < len1 + 1; i++)
    {
        for (int j = 0; j < len2 + 1; j++)
        {
            memoization[i][j] = 0;
        }
    }
    cout << "\n" << dynamic_solve(seq1, seq2, len1, len2, memoization) - 1 << "\n";

}

