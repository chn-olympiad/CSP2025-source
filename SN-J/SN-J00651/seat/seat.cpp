#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat3.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m; //为第 c 列. 第 r 行
	//n行 m列 
	deque<int> a;
	int all = n * m;
	for(int i = 0; i < all; i++)
	{
		int x;
		cin >> x;
		a.push_back(x); 
	}
	int xiaoR = a[0];
	sort(a.begin(), a.end(), cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1; j <= n; j++, cnt++)
			{
				if(a[cnt] == xiaoR)
				{	
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
		else
		{
			for(int j = n; j >= 1; j--, cnt++)
			{
				if(a[cnt] == xiaoR)
				{
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
} 
