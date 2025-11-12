#include<bits/stdc++.h>
using namespace std;
int t,n,a[6][20005],b[6][20005],s[6][20005];
int c[6][7],maxx[20005];
int sum[6];
int main()
{
	freopen("clubin","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	maxx[1]=-2;
	maxx[2]=-2;
	maxx[3]=-2;
	maxx[4]=-2;
	maxx[5]=-2;
	maxx[6]=-2;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j]>>b[i][j]>>s[i][j];
			c[i][1]=a[i][1]+b[i][2];
			c[i][2]=a[i][1]+s[i][2];
			c[i][3]=b[i][1]+a[i][2];
			c[i][4]=b[i][1]+s[i][2];
			c[i][5]=s[i][1]+a[i][2];
			c[i][6]=s[i][1]+b[i][2];
		}
		for(int m=1;m<=6;m++)
		{
			if(c[i][m]>maxx[i]) maxx[i]=c[i][m];
		}
	}
	cout<<maxx[1]<<endl<<endl;
	cout<<maxx[2];
	cout<<endl; 
	return 0;
}
