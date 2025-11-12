#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int sc,id;
}a[1010];
bool cmp(stu x,stu y)
{
	return x.sc>y.sc;
}
int sn[105][105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].sc,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	int me;
	for(int i=1;i<=n*m;i++)if(a[i].id==1)me=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1)
			{
				if(j==1)sn[i][j]=1;
				else 
				{
					if(j%2)sn[i][j]=sn[i][j-1]+1;
					else sn[i][j]=sn[i][j-1]+n*2-1;
				}
			}
			else
			{
				if(j%2)sn[i][j]=sn[i-1][j]+1;
				else sn[i][j]=sn[i-1][j]-1;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<sn[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(sn[i][j]==me)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

