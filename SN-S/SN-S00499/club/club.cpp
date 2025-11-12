#include<bits/stdc++.h>

using namespace std;

bool cmp(int x, int y);
void input();

int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int t;
	int n;
	int a, b, c;
	int d[100001], e[100001], f[100001];
	int i, j, k;
	int maxa;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> a >> b >> c;
		maxa = a;
		if(b == 0 && c == 0)
		{
			for(i = 2; i <= n; i++)
			{
				cin >> a >> b >> c;
				maxa = max(maxa, a);
				cout << maxa;
			}
		}
		else if(n == 2)
		{
			int b1, b2, b3;
			int c1, c2, c3, c4, c5, c6;
			cin >> b1 >> b2 >> b3;
			c1 = a + b2;
			c2 = a + b3;
			c3 = b + b1;
			c4 = b + b3;
			c5 = b + b1;
			c6 = b + b2;
			maxa = max(max(max(c1, c2), max(c3, c4)), max(c5, c6));
			cout << maxa;
		}
		
		maxa = 0;
	}
}

bool cmp(int x, int y)
{
	return(x > y);
}


