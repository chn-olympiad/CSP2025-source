#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],f[100005][4],num[100005][4][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		f[1][1]=a[1][1];
		f[1][2]=a[1][2];
		f[1][3]=a[1][3];
		num[1][1][1]=1;
		num[1][2][2]=1;
		num[1][3][3]=1;
		for(int i=2;i<=n;i++)
		{
			int q[4];
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					if(num[i-1][j][k]<(n/2) && ((f[i-1][j]+a[i][k])>f[i][k] || (f[i][k]==0)))
					{
						f[i][k]=f[i-1][j]+a[i][k];
						q[k]=j;
					}
				}
			}
			num[i][1][1]=num[i-1][q[1]][1]+1;
			num[i][1][2]=num[i-1][q[1]][2];
			num[i][1][3]=num[i-1][q[1]][3];
			num[i][2][2]=num[i-1][q[2]][2]+1;
			num[i][2][1]=num[i-1][q[2]][1];
			num[i][2][3]=num[i-1][q[2]][3];
			num[i][3][3]=num[i-1][q[3]][3]+1;
			num[i][3][1]=num[i-1][q[3]][1];
			num[i][3][2]=num[i-1][q[3]][2];
		}
		cout<<max(f[n][1],max(f[n][2],f[n][3]))<<"\n";
		
	}
	return 0;
}
