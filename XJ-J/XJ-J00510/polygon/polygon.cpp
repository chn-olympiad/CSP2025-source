#include<bits/stdc++.h>
using namespace std;
long long int n,a[5005],i,t,x1,x2,y1,y2,z1,z2; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	if(n==3)
	{
		x1=a[1]-a[2];x2=a[2]-a[1];
		y1=a[2]-a[3];y2=a[3]-a[2];
		z2=a[1]-a[3];z1=a[3]-a[1];
		if(a[1]<a[2]+a[3]&&a[1]>y1&&a[1]>y2)
		t=1;
		if(a[2]<a[1]+a[3]&&a[2]>z1&&a[2]>z2)
		t=1;
		if(a[3]<a[1]+a[2]&&a[3]>x1&&a[3]>x2)
		t=1;
		cout<<t;
	}
	return 0;	
}
