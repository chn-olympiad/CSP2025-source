#include<bits/stdc++.h>
using namespace std;
const int N=207;
int f[N][N>>1][N>>1];
int g[N][N>>1][N>>1];
int T,n,v1[N],v2[N],v3[N],idx[N];
void solve1()
{
	memset(f,-1,sizeof(f));
	memset(g,0,sizeof(g));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j1=0;j1<=n/2;j1++)
		{
			for(int j2=0;j2<=n/2;j2++)
			{
				int j3=i-j1-j2;
				if(j3>=0)
				{
					if(j1>0&&f[i-1][j1-1][j2]!=-1)
						f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1-1][j2]+v1[i]);
					if(j2>0&&f[i-1][j1][j2-1]!=-1)
						f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1][j2-1]+v2[i]);
					if(j3>0&&g[i-1][j1][j2]+1<=n/2&&f[i-1][j1][j2]!=-1)
						f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1][j2]+v3[i]),g[i][j1][j2]=g[i-1][j1][j2]+1;
				}
			}
		}
	}
	int ans=0;
	for(int j1=0;j1<=n/2;j1++)
	{
		for(int j2=0;j2<=n/2;j2++)
		{
			int j3=n-j1-j2;
			if(j3<=n/2)
				ans=max(ans,f[n][j1][j2]);
		}
	}
	cout <<ans<<endl;
	return ;
}
bool cmp(int a,int b)
{
	return v1[a]>v1[b];
}
void solve2()
{
	for(int i=1;i<=n;i++)
		idx[i]=i;
	sort(idx+1,idx+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=v1[idx[i]];
	cout <<ans<<endl;
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>v1[i]>>v2[i]>>v3[i];
		if(n<=207)solve1();
		else
		{
			bool z2=1,z3=1;
			for(int i=1;i<=n;i++)
				z2&=v2[i]==0,z3&=v3[i]==0;
			if(z2==1&&z3==1)
			{
				solve2();
			}
			else
				cout <<-1;
		}
	}
	return 0;
}
