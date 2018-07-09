#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkwin(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 2584)
				return 1;
		}
	}
	return 0;
}
int checklose(int **a, int n)
{
	return 0;
}
void initializeboard(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	}
	int i = rand() % n;
	int j = rand() % n;
	a[i][j] = 1;
	i = rand() % n;
	j = rand() % n;
	a[i][j] = 1;


}
void setrandomone(int **a, int n)
{
	int i = rand() % n;
	int j = rand() % n;
	while (a[i][j] != 0)
	{
		i = rand() % n;
		j = rand() % n;
	}
	a[i][j] = 1;
}
void moveright(int **a, int n)
{
	for (int j = n - 2; j >=0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			int k = j;
			while (k < n - 1 && a[i][k + 1] == 0 && a[i][k] != 0)
			{
				a[i][k + 1] = a[i][k];
				a[i][k] = 0;
				k++;
			}
		}
	}
}
void movedown(int **a, int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			int k = i;
			while (k< n - 1 && a[k + 1][j] == 0 && a[k][j] != 0)
			{
				a[k + 1][j] = a[k][j];
				a[k][j] = 0;
				k++;
			}
		}
	}
}
void moveup(int **a, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int k = i;
			while (k>0 && a[k - 1][j] == 0 && a[k][j] != 0)
			{
				a[k - 1][j] = a[k][j];
				a[k][j] = 0;
				k--;
			}
		}
	}
}
void moveleft(int **a, int n)
{
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			int k = j;
			while (k>0 && a[i][k - 1] == 0 && a[i][k] != 0)
			{
				a[i][k - 1] = a[i][k];
				a[i][k] = 0;
				k--;
			}
		}
	}
}
void printboard(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");

}
int ispresent(int s)
{
	int i;
	int a[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584 };
	for (i = 0; i < 18; i++)
	{
		if (s == a[i])
			break;
	}
	if (i == 18)
	{
		return 0;
	}
	return 1;
}
void addup(int **a, int n)
{
	int h[4][4] = { 0 };
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
			{
				int k = i;
				if(k>0 && h[k][j] == 0)
				{
					while (k > 0 && a[k - 1][j] == 0)
					{
						k--;
					}
					if (k == 0)
					{
						a[k][j] = a[i][j];
						a[i][j] = 0;
						h[k][j] = 1;
						h[i][j] = 1;
					}
					else
					{
						int s = a[i][j] + a[k - 1][j];
						if (ispresent(s))
						{
							a[k - 1][j] = s;
							a[i][j] = 0;
							h[k - 1][j] = 1;
							h[i][j] = 1;
						}
					}
				}
			}
		}
	}
	moveup(a, n);
	setrandomone(a, n);
}

void addleft(int **a, int n)
{
	int h[4][4] = { 0 };
	for (int j = n - 1; j > 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] != 0)
			{
				int k = j;
				if (k>0 && h[i][k] == 0)
				{
					while (k > 0 && a[i][k-1] == 0)
					{
						k--;
					}
					if (k == 0)
					{
						a[i][k] = a[i][j];
						a[i][j] = 0;
						h[i][k] = 1;
						h[i][k] = 1;
					}
					else
					{
						int s = a[i][j] + a[i][k-1];
						if (ispresent(s))
						{
							a[i][k-1] = s;
							a[i][j] = 0;
							h[i][k-1] = 1;
							h[i][j] = 1;
						}
					}
				}
			}
		}
	}
	moveleft(a, n);
	setrandomone(a, n);

}

void adddown(int **a, int n)
{

	int h[4][4] = { 0 };
	for (int i = 0; i < n - 1;i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
			{
				int k = i;
				if (k<n-1 && h[k][j] == 0)
				{
					while (k<n-1 && a[k + 1][j] == 0)
					{
						k++;
					}
					if (k == n-1)
					{
						a[k][j] = a[i][j];
						a[i][j] = 0;
						h[k][j] = 1;
						h[i][j] = 1;
					}
					else
					{
						int s = a[i][j] + a[k + 1][j];
						if (ispresent(s))
						{
							a[k + 1][j] = s;
							a[i][j] = 0;
							h[k + 1][j] = 1;
							h[i][j] = 1;
						}
					}
				}
			}
		}
	}
	movedown(a, n);
	setrandomone(a, n);
}

void addright(int **a, int n)
{
	int h[4][4] = { 0 };
	for (int j = 0; j < n-1 ; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] != 0)
			{
				int k = j;
				if (k<(n-1) && h[i][k] == 0)
				{
					while (k<n-1&& a[i][k + 1] == 0)
					{
						k++;
					}
					if (k == n-1)
					{
						a[i][k] = a[i][j];
						a[i][j] = 0;
						h[i][k] = 1;
						h[i][k] = 1;
					}
					else
					{
						int s = a[i][j] + a[i][k +1];
						if (ispresent(s))
						{
							a[i][k + 1] = s;
							a[i][j] = 0;
							h[i][k + 1] = 1;
							h[i][j] = 1;
						}
					}
				}
			}
		}
	}
	moveright(a, n);
	setrandomone(a, n);

}
struct user
{
	char *name;
	int score;
};
void main()
{
	int n,m=0,score;
	
	printf("1.Play Game\n2.LeaderBoard\n3.Replay Last Game\n");
	int choice;
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		printf("enter name:\n");
		char *na;
		na = (char *)malloc(sizeof(char) * 15);
		scanf_s("%14s", na, 15);
		na = "Pranitha";
		//struct user *u=NULL;
		//u->name = (char *)malloc(sizeof(char) * 15);
		//strcpy(u->name, na);
		//u->score = 0;
		scanf_s("%d", &n);
		int **board;
		board = (int **)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++)
		{
			board[i] = (int *)malloc(sizeof(int)*n);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				board[i][j] = 0;
		}
		initializeboard(board, n);
		printboard(board, n);
		int win = checkwin(board, n);
		int lose = checklose(board, n);
		while (!win&&!lose)
		{
			char ch;
			printf("W-Up A-Left S-Down R-Right\n");
			printf("Enter Move\n");
			scanf_s("%c", &ch);
			scanf_s("%c", &ch);
			system("cls");
			if (ch == 'W')
				addup(board, n);
			if (ch == 'A')
				addleft(board, n);
			if (ch == 'S')
				adddown(board, n);
			if (ch == 'D')
				addright(board, n);
			printboard(board, n);
			m++;
			printf("Moves: %d\n", m);
		}
		score = m;
		FILE *f;
		
		if (win == 1)
			printf("Congratulations,%s...You won in %d moves", na, m);
	}
	else if (choice == 2)
	{

	}
	scanf_s("%d", &n);
}
