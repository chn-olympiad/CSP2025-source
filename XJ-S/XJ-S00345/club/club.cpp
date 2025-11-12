#include<bits/stdc++.h>
using namespace std;
int a[1000005][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
 	int i,j,k,m,n,t,maxi=-9,s=0;
 	cin>>t;
 	for(i=1;i<=t;i++)
 	{
 		s=0;
 		cin>>n;
 		for(j=1;j<=n;j++)
 		{
 			for(k=1;k<=3;k++)
 			{
 				cin>>a[j][k];
			}
		}
		for(j=1;j<=n;j++)
		{
		 	maxi=-9;
		 	for(k=1;k<=3;k++)
		 	{
		 		if(a[j][k]>maxi)
		 		{
		 			maxi=a[j][k];
				}
			 }
			 s=s+maxi;
		}
		 cout<<s<<endl;
	}
 	return 0;
}
