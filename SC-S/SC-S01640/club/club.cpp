#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N][4];
int club(int m)
{
	int tot2=0,tot1=0,b1[N]={},b2[N]={};
	for(int i=1;i<=m;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=m;i++)
		{
			int t,maxl=-1;
			for(int j=1;j<=3;j++)
			{
				if(b1[j]<m/2&&a[i][j]>maxl)
				{
					maxl=a[i][j];
					t=j;
				}
			}
			b1[t]++;
			tot1+=maxl;
		}
		for(int i=m;i>=1;i--)
		{
			int t,maxl=-1;
			for(int j=1;j<=3;j++)
			{
				if(b2[j]<m/2&&a[i][j]>maxl)
				{
					maxl=a[i][j];
					t=j;
				}
			}
			b2[t]++;
			tot2+=maxl;
		}	
	return max(tot1,tot2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,total[N];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		total[i]=club(n);
	}
	for(int i=1;i<=t;i++) cout<<total[i]<<endl;
	return 0;
}