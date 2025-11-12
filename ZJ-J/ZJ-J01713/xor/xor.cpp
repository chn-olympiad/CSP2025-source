#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int flag = 1, cnt = 0, ans = 0, sum = 0;
	for(int i = 1; i <= n; i ++) 
	{
		scanf("%d", &a[i]);
		if(a[i] == 1) cnt ++; 	
		else if(a[i] == 0) sum ++;
		else ans ++;
	}
	int op = 0;
	if(ans == 0)
	{
		if(sum == 0) 
		{
			if(k > 1) 
			{
				cout << 0;
				return 0;
			}
			if(k == 1) 
			{
				cout << n;
				return 0;	
			}
			if(k == 0)
			{
				cout << n / 2;
				return 0;
			}
		}
		else
		{
			if(k > 1) 
			{
				cout << 0;
				return 0;
			}
			if(k == 1)
			{
				for(int i = 1; i <= n; i ++) if(a[i] == 1) op ++;
				cout << op;
				return 0;
			}
			if(k == 0)
			{
				int l = 1e6, r = 0;
				for(int i = 1; i <= n - 1; i ++)
				{
					if(a[i] == 1 && a[i + 1] == 1 && ((i + 1 < l) || (i > r))) op ++,l = i, r = i + 1;
				}
				cout << op;
				return 0;
			}
		}
	}
	else
	{
		int p;
		int l = 1e6, r = 0;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = i; j <= n; j ++)
			{
				if(i > r || j < l)
				{
					p = a[i];
					for(int e = i + 1; e <= j; e ++)
					{
						p = p ^ a[e];
					}
					if(p == k) op ++, l = i, r = j;
				}
			}
		}
		cout << op;
		return 0;
	}
	return 0;
}
