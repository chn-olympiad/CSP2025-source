#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,u[101],v[101],w[101],c[101],a[101],sum=0,b=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<m;j++)
			cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(w[i]<w[i+1])
			b=w[i];
	}
	sum+=b;
	for(int i=0;i<=n-1;i++)
	{
		if(w[i]>w[i+1])
			b=w[i+1];
	}
	sum+=b;
	for(int i=0;i<k;i++)
	{
		if(c[i]<b)
			b=c[i];
	}
	sum+b;
	for(int i=0;i<n;i++)
	{
		if(u[i]<u[i+1])
		b=u[i];
	}
	sum+b;
	for(int i=0;i<m;i++)
	{
		if(v[i]<v[i+1])
		b=v[i];
	}
	sum+b;
	cout<<sum;
	return 0;
}
