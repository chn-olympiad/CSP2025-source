//BYD一小时后发现自己打错了吗，那很有意思了 
#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int T,n;
int a[100025][4],p[4][100025];
int fir(int x,int y,int z)
{
	if(x>y)
	{
		if(y>z) return 1;
		else //x>y y<z
		{
			if(x>z) return 1;
			else return 3; 
		}
	}
	else //x<y
	{
		if(x>z) return 2;
		else
		{
			if(y>z) return 2;
			else return 3;
		}
	}
}
int sec(int j,int x)
{
	int y,mxx=-1;
	for(int k=1;k<=3;k++)
	{
		if(k==x) continue;
		else if(mxx<a[j][k])
		{
			mxx=a[j][k];
			y=k;
		}
	}
	return y;
}
struct ilj{
	int x,del;
};
bool cmp(ilj s,ilj q)
{
	return s.del<q.del;
}
void solve()
{
	int sum=0;
	memset(p,0,sizeof(p));
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	
	for(int i=1;i<=n;i++)
	{
		int x=fir(a[i][1],a[i][2],a[i][3]);
		p[x][++p[x][0]]=i;
		sum+=a[i][x];
	}
	
	int b[100025];
	int m,flag=0;
	for(int i=1;i<=3;i++)
	{
		if(p[i][0]>n/2)
		{
			flag=1;
			m=p[i][0];
			for(int j=1;j<=m;j++)
			{
				int y=sec(p[i][j],i);
				b[j]=a[p[i][j]][i]-a[p[i][j]][y];
			}
		}
	} 
	if(flag==1)
	{
		sort(b+1,b+1+m);
		for(int i=1;i<=m-n/2;i++) sum-=b[i];
	}
	
	cout<<sum<<'\n';
	
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--) solve();
	
	return 0;
}
