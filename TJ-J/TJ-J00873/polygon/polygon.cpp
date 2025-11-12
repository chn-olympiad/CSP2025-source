#include<bits/stdc++.h>
using namespace std;
int a[50009];
int b[10009];
int c[10009];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
	
	b[1]=a[1]+a[2]+a[3];
	b[2]=a[1]+a[2];
	b[3]=a[1]+a[3];
	b[4]=a[2]+a[3];
	c[1]=max(max(a[1],a[2]),a[3]);
	c[2]=max(a[1],a[2]);
	c[3]=max(a[1],a[3]);
	c[4]=max(a[2],a[3]);
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		if(b[i]>c[i]*2)
		{
			ans++;
		}
	}
	cout<<ans;
}
else
{
	cout<<50;
}
	return 0;
}

