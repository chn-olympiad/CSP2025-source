#include<bits/stdc++.h>

using namespace std;

int n, k;
int a[500001];
int ans;

void input();
void calcu();

signed main()
{
	freopen("xor.in", 'r', stdin);
	freopen("xor.out", 'w', stdout);
	input();
	calcu();
	cout << ans << endl;
}

void calcu()
{
	int i, j;
	int x;
	
	for(i = 1; i <= n; i++)
	{
		x = a[i];
		if(x == k)
		{
			ans++;
			continue;
		}
		for(j = i + 1; j <= n; j++)
		{
			x = int(x ^ a[j]);
			if(x == k)
			{
				ans++;
				i = j;
				break;
			}
			else if(a[j] == k)
			{
				ans++;
				i = j;
				break;
			}
		}
	}
}

void input()
{
	int i;
	
	cin >> n >> k;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
}
