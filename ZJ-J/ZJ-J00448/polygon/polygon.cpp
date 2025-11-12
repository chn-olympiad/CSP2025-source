#include <bits/stdc++.h>
using namespace std;
long long mod=998244353; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c,i,j;
	cin>>n;
	if(n==3)
	{
		cin>>a>>b>>c;
		if(a+b>c && a-b<c)
			cout<<1;
		else
			cout<<0;
	}		
	return 0;
}
