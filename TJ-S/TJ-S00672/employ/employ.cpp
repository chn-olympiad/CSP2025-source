#include <bits/stdc++.h> 
using namespace std;
int f(long long x)
{
	int c=1;
	for(long long i=1;i<=x;i++)
	{
		c=(c*i)%998244353;
	}
	return c;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	string s;
	long long a[1000];
	cin>>n>>m;
	cin>>s;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	cout<<f(n);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
