#include <bits/stdc++.h>
using namespace std;
long long t, n, a[100005][4], maxn, x[4], maxm[7], k[100005];
bool o;
void dfs(long long member, long long sum, long long b[4])
{
	if(member > n)
	{
		if(sum >= maxn)
		{
			maxn = sum;
		}
		else
		{
			return ;
		}
	}
	for(int i = 1; i <= 3; i++)
	{
		if(b[i] + 1 > n / 2)
		{
			continue;
		}
		b[i]++;
		dfs(member + 1, sum + a[member][i], b);
		b[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			if(a[j][2] != 0 || a[j][3] != 0)
			{
				o = true;
			} 
		}
		if(!o)
		{
			for(int j = 1; j <= n; j++)
			{
				k[j] = a[j][1];
			}
			sort(k + 1, k + 1 + n);
			for(int j = n / 2 + 1; j <= n; j++)
			{
				cout << k[j] << '-' << maxn << endl;
				maxn += k[j];
			}
			maxm[i] = maxn;
			maxn = 0;
			continue;
		}
		dfs(1, 0, x);
		maxm[i] = maxn;
		maxn = 0;
	}
	for(int i = 1; i <= t; i++)
	{
		cout << maxm[i] << endl;
	} 
	return 0;
}
