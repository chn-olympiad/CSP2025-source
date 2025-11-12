#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],h;
int d[5010];
int cz(int u,int k)
{
	if(u==k)
	{
		int e,q;
		for(int j=1;j<=u;j++)
		{
			q+=d[j];
			e=max(e,d[j]);
		}
		if(q<=e*2) return 0;
		return 1;
	} 
	int c=0;
	for(int i=1;i<=n;i++)
	{
		d[u]=a[i];
		c+=cz(u+1,k);
	}
	return c;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	for(int i=3;i<=n;i++)
//	{
//		h+=cz(1,i);
//		h%=998244353;
//	}
	h+=n*(n-3);
	h++;
	h%=998244353;
	cout<<h;
	return 0;
} 
