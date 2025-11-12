#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int r, c;
int flag, flagi;
int a[101];

void input();
void init();
void calcu();

signed main()
{
	freopen("seat.in", 'r', stdin);
	freopen("seat.out", 'w', stdout);
	input();
	init();
	calcu();
	cout << c << " " << r << endl;
	return 0;
}

void calcu()
{
	int a, b;
	
	a = flagi / n;
	b = flagi % n;
	if(b == 0)
	{
		c = a;
		if(c % 2 == 0)
		{
			r = 1;
		}
		else
		{
			r = n;
		}
	}
	else
	{
		c = a + 1;
		if(c % 2 == 0)
		{
			r = n - b + 1;
		}
		else
		{
			r = b;
		}
	}
}

void init()
{
	int i;
	
	flag = a[1];
	sort(a + 1, a + n * m + 1);
	for(i = 1; i <= n * m; i++)
	{
		if(a[i] == flag)
		{
			flagi = n * m - i + 1;
			break;
		}
	}
}

void input()
{
	int i;
	
	cin >> n >> m;
	for(i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
}
