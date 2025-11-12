#include<bits/stdc++.h>
using namespace std;
int t,n,a[50010][4],xz[4],pl[100010];
int maxn;
void bl(int x[],int dj,int dq)
{
	if(dj==n+1)
	{
		maxn=max(maxn,dq);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(xz[i]<n/2)
		{
			xz[i]++;
			bl(x,dj+1,dq+a[dj][i]);
			xz[i]--;
		}
	}
	return ;
}
int main()
{
	freopen("club,in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		bool fa=1,fa1=1;
		maxn=-0x7f7f7f7f;
		xz[1]=xz[2]=xz[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			if(!(a[i][2]==a[i][3]&&a[i][2]==0))
				fa=0;
		for(int i=1;i<=n;i++)
			if(!(a[i][3]==0))
				fa1=0;
		if(n<=10)
		{
			bl(xz,1,0);
			cout<<maxn<<endl;
		}
		else if(fa)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				pl[i]=a[i][1];
			sort(pl+1,pl+n+1);
			for(int i=n;i>n/2;i--)
				sum+=pl[i];
			cout<<sum<<endl;
		}
		else if(fa1)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				pl[i]=a[i][1]-a[i][2];
				sum+=a[i][2];
			}
			sort(pl+1,pl+n+1);
			for(int i=n;i>n/2;i--)
				sum+=pl[i];
			cout<<sum<<endl;
		}
	}
	return 0;
}