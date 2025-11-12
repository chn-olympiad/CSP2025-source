#include<bits/stdc++.h>
using namespace std;
long long v[100000];
long long m[100000];
	long long n;
	long long k = 0;
void dfs(long long x,long long c)
{
	if (x == n)
	{
		long long s = 0,maxn = INT_MIN;
		for (long long i = 1;i <= n;i++)
		{
			s += v[i] * m[i];
			maxn = max(maxn,v[i] * m[i]);
			
//			if (m[i]) cout<<v[i]<<" ";
		}
//		cout<<"/"<<s<<endl;
		if (s > maxn * 2) 
		{
			k++;
			k %= 998244353;
		}
		return ;
	}
	m[x + 1] = 1;
	dfs(x + 1,c);
	m[x + 1] = 0;
	dfs(x + 1,c);
	
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (long long i = 1;i <= n;i++)
	{
		cin>>v[i];
	}
//	long long l = v[0].k;
	sort(v,v + n);
	dfs(0,0);
	cout<<k;
	return 0;
}
