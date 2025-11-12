#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,m,z;
	cin>>n;
	int a[n];
		for(int j=3;j<=m;j++)
		{
			z=j;
			for(int i=1;i<=n;i++)
			{
		    j=j+(j+1);
			z=z*z;
		    if(m>=3&&j>z*2)
		    cnt++;
		}
    }
cout<<cnt;
return 0;	
} 
