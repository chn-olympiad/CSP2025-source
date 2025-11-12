#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2) cout<<0;
	if(n==3)
	{
		int x=a[1],y=a[2],z=a[3];
		if((max(x,max(y,z))-min(x,min(y,z)))>=(x+y+z-max(x,max(y,z))-min(x,min(y,z)))) cout<<1;
		else cout<<0;
	}
	return 0;
}
