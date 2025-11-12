#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int n;
int k;
int ans;
bool flg1;
bool flg2;
int t[500005];
int a[500005];
int sum[500005];
int dp[500005];
int lowbit(int x)
{
	return (x&(-x));
}
int q(int i)
{
	int res = 0;
	while(i)
	{
		res = max(res,t[i]);
		i-=lowbit(i);
	}
	return res;
}
void add(int i, int v)
{
	while(i<=n)
	{
		t[i] = max(t[i],v);
		i+=lowbit(i);
	}
}
int main()
{
	fre();
	cin>>n>>k;
	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i] != 1)
		{
			flg1 = true;
		}
		if(a[i]>1)
		{
			flg2 = true;
		}
		sum[i] = sum[i-1]^a[i];
	}
	if(!flg1)
	{
		cout<<n/2;
		return 0;
	}
	else if(!flg2)
	{
		int res = 0;
		if(k == 0)
		{
			bool t = false;
			for(int i = 1; i<=n; i++)
			{
				if(a[i] == 0)
				{
					res++;
					t = false;
				}
				else
				{
					if(!t)
					{
						t = true;
					}
					else
					{
						res++;
						t = false;
					}
				}
			}
		}
		else
		{
			for(int i = 1; i<=n; i++)
			{
				if(a[i] == 1)
				{
					res++;
				}
			}
		}
		cout<<res;
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		dp[i] = 0;
		for(int j = 0; j<i; j++)
		{
			if((sum[i]^sum[j]) == k)
			{
				dp[i] = max(dp[i],q(j)+1);
			}
		}
		add(i,dp[i]);
	}
	int ans = 0;
	for(int i = 1; i<=n; i++)
	{
		ans = max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
