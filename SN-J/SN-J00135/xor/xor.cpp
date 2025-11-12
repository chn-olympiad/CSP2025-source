#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[1000000];

int ans;

void input();
void dfs(int l, int cnt);

signed main()
{
	//一定不要忘记删啊 
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	//一定不要忘记删啊 
	
	int i;
	
	input();
	for(i = 1; i <= n; i++)
	{
		dfs(i, 0);	
	}
	//对于每个区间进行深搜 
	cout << ans;
}

void dfs(int l, int cnt)
{
	int i;
	int r;
	int num;
	
	r = l;
	num = 0;
	while(r <= n)
	{
		num = num xor a[r];	
		if(num == k)
		{
			break;
		}
		r++;
	}
	if(num == k)
	{
		cnt++;
	}
	ans = max(ans, cnt);
	for(i = r + 1; i <= n; i++)
	{
		dfs(i, cnt);
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

/*
4 2
2 1 0 3
*/
