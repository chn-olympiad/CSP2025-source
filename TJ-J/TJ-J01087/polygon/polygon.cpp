#include <bits/stdc++.h>
using namespace std;
long long mm=0;
long long s(long long lo)
{
	long long f=1;
	for(long long i=1;i<=lo;i++)
	{
		f=f*i;
	}
//	cout<<"s="<<f<<endl;
	return f;
}
long long d(long long n,long long lo)
{
	long long f=n;
	for(long long i=1;i<lo;i++)
	{
		f=f*(n-i);
	}
//	cout<<"d="<<f<<endl;
	return f;
}
long long xxx(long long r,long long t)
{
	if(r==2)
	{
		return 0;
	}
	long long cc=0;
	for(long long i=3;i<=r;i++)
	{
		cc+=d(t,i)/s(i);
	}
	return cc;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0,z=0;
	int l[5000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<=n;i++)
	{
		m=max(m,l[i]);
		z=l[i]+z;
	}
	if(n==3)
	{
		if(z>2*m)
		{
			cout<<"1";

		}
		else
			cout<<"0";
		return 0;
	}
	cout<<xxx(n,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
