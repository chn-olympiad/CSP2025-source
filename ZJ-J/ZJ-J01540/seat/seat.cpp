#include<bits/stdc++.h>
using namespace std;
int n,m;
int fs[205];
int Rfs,Rth,cnt;
int a[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&fs[i]);
	Rfs=fs[1];
	sort(fs+1,fs+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				a[j][i]=fs[++cnt];
		}
		else
		{
			for(int j=n;j>=1;j--)
				a[j][i]=fs[++cnt];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(a[i][j]==Rfs)
			{
				cout<<j<<" "<<i;
				return 0;
			}
	}
}
