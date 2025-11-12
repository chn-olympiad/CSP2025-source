#include <bits/stdc++.h>
using namespace std;
long long f(long long a)
{
	if(a==1||a==2)
	{
		return a;
	}
	else return a*f(a-1);
}
int main()
{
	int a,b,c;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	if(f(b)%998244353<0)
	{
		c=0;
	}
	else
	{
		c=f(b)%998244353;
	}
	cout<<c;
	return 0;
}
