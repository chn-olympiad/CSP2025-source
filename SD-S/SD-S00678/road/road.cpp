#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[15][10005],b[10005],fl[15];
struct node
{
	int v,w;
};
vector<node>e[10005]; 
long long ans=1e16;
void dfs1(int x,long long s,int f)
{
	//cout<<x<<" "<<s<<" "<<" "<<f<<"\n";
	if(f==n)
	{
		ans=min(ans,s);
		return ;
	}
	if(s>=ans)
		return ;
	int h=0;
	for(auto v:e[x])
	{
		if(!b[v.v])
		{
			h+=v.w;
			b[v.v]=1;
			dfs1(v.v,s+v.w,f+1);
			b[v.v]=0;
		}
	}
	int k=0;
	for(auto v:e[x])
	{
		if(!b[v.v])
			k++;
	}
	for(auto v:e[x])
	{
		if(!b[v.v])
		{
			for(auto v:e[x])
				b[v.v]=2;
			dfs1(v.v,s+h,f+k);
			for(auto v:e[x])
				if(b[v.v]==2)
					b[v.v]=0;
		}
	}
	return ;
}
void dfs(int x,long long s,int f)
{
	//cout<<x<<" "<<s<<" "<<" "<<f<<"\n";
	if(f==n)
	{
		ans=min(ans,s);
		return ;
	}
	if(s>=ans)
		return ;
	for(auto v:e[x])
	{
		if(!b[v.v])
		{
			b[v.v]=1;
			dfs(v.v,s+v.w,f+1);
			if(k)
			{
				for(int i=1;i<=k;i++)
				{
					int h=a[i][0],g=a[i][x],l=a[i][v.v];
					a[i][0]=a[i][x]=a[i][v.v]=0;
					if(fl[k])
						dfs(v.v,s+h+l,f+1);
					else
					{
						fl[k]=1;
						dfs(v.v,s+h+l+g,f+1);
						fl[k]=0;
					}					
					//cout<<h<<" "<<g<<" "<<l<<"\n";					
					a[i][0]=h,a[i][x]=g,a[i][v.v]=l;
				}
			}
			b[v.v]=0;
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	long long as=1e16;
	for(int i=1;i<=k;i++)
	{
		long long r=0;
		for(int j=0;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			r+=a[i][j];
		}
		as=min(as,r);
	}
	if(as==0)
	{
		cout<<0;
		return 0;
	}
	b[1]=1;
	dfs1(1,0,1);
	if(k)
		dfs(1,0,1);
	cout<<ans;
	return 0;
} 
//4 4 2 
//1 4 6
//2 3 7
//4 2 5
//4 3 5
//1 1 8 2 4
//100 1 3 2 4
