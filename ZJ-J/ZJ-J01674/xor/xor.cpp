#include<bits/stdc++.h>

using namespace std;

int p[500005];
int a[500005];

struct Node
{
	int x;
	int y;
};

bool cmp(Node x, Node y)
{
	return x.y < y.y;
}

Node s[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	
	int num = 0;
	
	for(int i = 0; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int now = p[j] ^ p[i + 1];
			if(now == k)
			{
				s[++num] = {i + 1, j};
			}
		}
	}
	
	sort(s + 1, s + num + 1, cmp);
	
	int last = 0;
	int ans = 0;
	for(int i = 1; i <= num; i++)
	{
		if(last < s[i].x)
		{
			last = s[i].y;
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}
