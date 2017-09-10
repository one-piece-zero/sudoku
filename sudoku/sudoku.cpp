#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int sudoku[10][10];    /*数独矩阵*/
int N, i, j;
int find(int, int);    /*完成数独函数*/
int main()
{
	
	int no = (2 + 3) % 9 + 1;
	cin >> N;
	srand((unsigned)time(NULL));/*以当前的系统时间产生随机数*/
	for (int l = 0; l<N; l++)
	{

		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
				sudoku[i][j] = 0;
		}                                  /*令数独矩阵全为0*/
		for (int i = 1; i <= 9; i++)
		{
			sudoku[1][i] = i;              /*初始化数独矩阵第一行*/
		}
		sudoku[1][1] = no;                 
		sudoku[1][no] = 1;
		random_shuffle(&(sudoku[1][2]), &(sudoku[1][9]));   /*第一行第一个数为6，后八个数随机排列*/
		find(2, 1);           /*调用find函数，从第二行第一个数开始完成数独*/
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
				cout << sudoku[i][j] << " ";
			cout << endl;
		}/*输出结果*/
		cout << endl;
	}
	system (" pause ");
	return 0;
}
int find(int i, int j)
{
	int flag;
	if (i > 9 || j > 9)
		return 1;
	for (int k = 1; k <= 9; ++k)
	{
		flag = 1;
		for (int m = 1; m<i; ++m)
			if (sudoku[m][j] == k)
			{
				flag = 0;
				break;
			}
		if (flag)
		{
			for (int n = 1; n<j; ++n)
				if (sudoku[i][n] == k)
				{
					flag = 0;
					break;
				}
		}
		if (flag)
		{
			int x = (i / 3) * 3 + 3;
			int y = (j / 3) * 3 + 3;
			if (i % 3 == 0)
			{
				x = i;
			}
			if (j % 3 == 0)
			{
				y = j;
			}
			for (int a = x - 2; a <= x; ++a)  /* 检查在每个宫中是否出现了同一个数字 */
			{
				if (flag == 0)
					break;
				for (int b = y - 2; b <= y; ++b)
					if (sudoku[a][b] == k)
					{
						flag = 0;
						break;
					}
			}
		}
		if (flag)
		{
			sudoku[i][j] = k;
			if (j<9)
			{
				if (find(i, j + 1))   /* 到同一行的下一位置开始搜索 */
					return 1;
			}
			else
			{
				if (i < 9)
				{
					if (find(i + 1, 1))    /* 到下一行的第一个空格开始搜索 */
						return 1;
				}
				else
					return 1;  /* 当行数或列数超过9时  , 搜索结束 */

			}
			sudoku[i][j] = 0;   /* 若无解，则回复至初始 */
		}
	}
	return 0;  /* 若所有数字均试过不可行，则返回再查找 */
}

