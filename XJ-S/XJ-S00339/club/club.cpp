#include<bits/stdc++.h>
using namespace std;
int t,n,a[10],m,p[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		int z=0;
		for(int i=1;i<=n;i++)
		{
			
			cin>>a[1]>>a[2]>>a[3];
			if(a[1]>a[2]&&a[1]>a[3]) z+=a[1];
			if(a[2]>a[1]&&a[2]>a[3]) z+=a[2];
			if(a[3]>a[2]&&a[3]>a[1]) z+=a[3];
			
		}
		p[j]=z;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<p[i]<<"\n";
	}
	return 0;	
} 
