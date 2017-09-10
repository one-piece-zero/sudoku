#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int sudoku[10][10];    /*��������*/
int N, i, j;
int find(int, int);    /*�����������*/
int main()
{
	
	int no = (2 + 3) % 9 + 1;
	cin >> N;
	srand((unsigned)time(NULL));/*�Ե�ǰ��ϵͳʱ����������*/
	for (int l = 0; l<N; l++)
	{

		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
				sudoku[i][j] = 0;
		}                                  /*����������ȫΪ0*/
		for (int i = 1; i <= 9; i++)
		{
			sudoku[1][i] = i;              /*��ʼ�����������һ��*/
		}
		sudoku[1][1] = no;                 
		sudoku[1][no] = 1;
		random_shuffle(&(sudoku[1][2]), &(sudoku[1][9]));   /*��һ�е�һ����Ϊ6����˸����������*/
		find(2, 1);           /*����find�������ӵڶ��е�һ������ʼ�������*/
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
				cout << sudoku[i][j] << " ";
			cout << endl;
		}/*������*/
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
			for (int a = x - 2; a <= x; ++a)  /* �����ÿ�������Ƿ������ͬһ������ */
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
				if (find(i, j + 1))   /* ��ͬһ�е���һλ�ÿ�ʼ���� */
					return 1;
			}
			else
			{
				if (i < 9)
				{
					if (find(i + 1, 1))    /* ����һ�еĵ�һ���ո�ʼ���� */
						return 1;
				}
				else
					return 1;  /* ����������������9ʱ  , �������� */

			}
			sudoku[i][j] = 0;   /* ���޽⣬��ظ�����ʼ */
		}
	}
	return 0;  /* ���������־��Թ������У��򷵻��ٲ��� */
}

