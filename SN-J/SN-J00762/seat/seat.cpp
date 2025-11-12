#include<bits/stdc++.h>

using namespace std;

int n, m;//n––m¡–
int a[101];
int b[101];
int c[11][11];
int d[101];

void input();
void calcu();

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	input();
	sort(a + 1, a + 1 + n * m);
	
	calcu();
	return 0;
}

void calcu()
{	
	int i;
	int cnt = 0;
	int row, col;
	
	for(i = 1; i <= n * m; i++)
	{
		if(b[a[i]] == 1)
		{
			cnt++;
			//cout << cnt << endl;
			break;
		}
		cnt++;
	}
	cnt = n * m - cnt + 1;
	if(cnt % n == 0)
	{
		col = cnt / n;
		if(col % 2 != 0)
		{
			row = n;
		}
		else
		{
			row = 1;
		}
	}
	else
	{
		col = cnt / n + 1;
		if(col % 2 != 0)
		{
			row = cnt - (col - 1) * n;
		}
		else
		{
			row = n - (cnt - (col - 1) * n - 1);
		}
	}
	cout << col << ' ' << row;
}

void input()
{
	int i;
	int mark;
	
	cin >> n >> m;
	for(i = 1; i <= n * m; i++)
	{
		cin >> mark;
		a[i] = mark;
		b[mark] = i;
	}
}
