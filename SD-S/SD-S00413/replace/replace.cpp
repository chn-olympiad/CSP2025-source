#include<bits/stdc++.h>

using namespace std;
int t;

struct node
{
	int f,s,t;
	int maxn;
}a[110000];
bool cmp(node a,node b)
{
	return a.maxn>b.maxn;
}
int ans;
int main()
{
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].f<<a[i].s<<a[i].t;
			a[i].maxn=max(a[i].f,max(a[i].s,a[i].t));
		}
		int maxn1=n/2;
		int maxn2=n/2;
		int maxn3=n/2;
		for(int i=1;i<=n;i++)
		{
			if(a[i].maxn==a[i].f)
			{
				ans+=a[i].maxn;
				maxn1--;
			}
		}
	}
	return 0;
}

