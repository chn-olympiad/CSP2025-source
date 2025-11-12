#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10000],p;
bool c(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p+=a[i];
	}
	sort(a+1,a+n+1,c);
	if(n<=3)
	{
		if(a[2]+a[3]>a[1])
		{
			cout<<1;
		}
	}
	
	
	
	return 0;
}
