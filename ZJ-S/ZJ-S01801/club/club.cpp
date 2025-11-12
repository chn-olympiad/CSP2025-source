#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct YG{
	int x,y,z,cha;
}a[300007];
int f[207][207][207];
bool cmp(YG q,YG w)
{
	return q.x>w.x;
}
bool cmp2(YG q,YG w)
{
	return q.y-q.x>w.y-w.x;
}
int slve1()
{
	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<i+j;k++)
			{
				f[k][i+1][j+1]=-1e9-7;
			}
		}
	}*//*
	for(int i=1;i<=n;i++)
	{
		if(i<=m)
			f[i][0][0]=f[i-1][0][0]+a[i].z;
		int q=min(i,m);
		for(int x=1;x<=q;x++)
		{
			if(i-x<=m)
				f[i][x][0]=max(f[i-1][x-1][0]+a[i].x,f[i-1][x][0]+a[i].z),//err<<i<<x<<"-"<<f[i][x][0]<<"\n";
		}
		for(int y=1;y<=q;y++)
		{
			if(i-y<=m)
				f[i][0][y]=max(f[i-1][0][y-1]+a[i].y,f[i-1][0][y]+a[i].z),//err<<i<<y<<"-"<<f[i-1][0][y-1]<<","<<f[i-1][0][y]<<","<<f[i][0][y]<<"\n";
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=i;x++)
		{
			for(int y=1;y<=i-x;y++)
			{
				int z=i-x-y;
				if(x>m||y>m||z>m)
				{
					break;
				}
				f[i][x][y]=max(f[i-1][x-1][y]+a[i].x,max(f[i-1][x][y-1]+a[i].y,f[i-1][x][y]+a[i].z));
				
				//err<<x<<"-"<<y<<"-"<<n-x-y<<"-"<<f[n][x][y]<<"\n";
			}
			
		}
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<=i;x++)
		{
			for(int y=0;y<=i-x;y++)
			{
				int z=i-x-y;
				if(x>m||y>m)
				{
					break;
				}
				if(z>m)
				{
					continue;
				}
				if(x>0)
				{
					f[i][x+1][y+1]=max(f[i-1][x-1+1][y+1]+a[i].x,f[i][x+1][y+1]);
				}
				if(y>0)
				{
					f[i][x+1][y+1]=max(f[i-1][x+1][y-1+1]+a[i].y,f[i][x+1][y+1]);
				}
				if(z>0)
				{
					f[i][x+1][y+1]=max(f[i-1][x+1][y+1]+a[i].z,f[i][x+1][y+1]);
				}
				//f[i][x+1][y+1]=max(f[i-1][x-1+1][y+1]+a[i].x,max(f[i-1][x+1][y-1+1]+a[i].y,f[i-1][x+1][y+1]+a[i].z));
				////err<<x<<"-"<<y<<"-"<<z<<"-"<<f[i][x+1][y+1]<<"\n";
			}
		}
	}
	ans=0;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			////err<<i<<"-"<<j<<"-"<<n-i-j<<"-"<<f[n][i][j]<<"\n";
			ans=max(ans,f[n][i+1][j+1]);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				//err<<f[k][i+1][j+1]<<" ";
				//ans=max(ans,f[n][i][j]);
			}
			//err<<"\n";
		}
		//err<<"\n";
	}
	return ans;
}
void mian()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=205;i++)
	{
		for(int j=1;j<=205;j++)
		{
			for(int k=1;k<=205;k++)
			{
				f[i][j][k]=0;
			}
		}
	}
	m=n/2;
	int cs1=0,cs2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		cs1+=a[i].y;
		cs2+=a[i].z;
	}
	if(n<=200)
	{
		cout<<slve1()<<"\n";
	}
	else
	{
		if(cs1==0)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=m;i++)
			{
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
		}
		else if(cs2==0)
		{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=m;i++)
			{
				ans+=a[i].y;
				ans+=a[i+m].x;
			}
			cout<<ans<<"\n";
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		//err<<"_____________________\n";
		mian();
	}
}
/*



1
4
1 100 200
1 100 200
1 100 200
1 199 201



*/
