#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
};
struct node q[1000005];
int a[1000005];
int s[1000005];
bool cmp(node x,node y)
{
	if(x.r == y.r)
	{
		return x.l > y.l;
	}
	return x.r < y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt1 = 0,cnt0 = 0;
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i] == 1)
		{
			cnt1++;
		}
		if(a[i] == 0)
		{
			cnt0++;
		}
	}
	if(cnt1 == n)
	{
		if(k == 0)
		{
			cout<<n / 2;
		}
		if(k == 1)
		{
			cout<<n;
		}
		if(k > 1)
		{
			cout<<0;
		}
	}
	else if(cnt0 + cnt1 == n)
	{
		if(k == 0)
		{
			cout<<(cnt1 / 2) + cnt0;
		}
		if(k == 1)
		{
			cout<<cnt1;
		}
		if(k > 1)
		{
			cout<<0;
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			s[i] = s[i - 1] ^ a[i];
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;j++)
			{
				int xoradd = s[j] ^ s[i - 1];
				if(xoradd == k)
				{
					q[++cnt] = {i,j};
				}
			}
		}
		sort(q + 1,q + cnt + 1,cmp);
		int t = q[1].r,id = 2,ans = 1;
		while(t <= n && id <= cnt)
		{
			while(q[id].l <= t && id <= cnt)
			{
				id++;
			}
			ans++;
			t = q[id].r;
			id++;
		}
		cout<<ans - 1;
	}
	return 0;
}
