#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x,y,z,w[11],ans=0,kk;
int tot=1,vis[10009],h[11],m1,t1;
int fa[10009][2];
struct node{
	ll x,y,z;
	bool operator<(const node &b)const{
	return z<b.z;}
};
vector<node>b;
vector<ll>c[11];
vector<int>use;
int head(int x)
{
	if(fa[x][0]==x) return x;
	return head(fa[x][0]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		b.push_back(node{x,y,z});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&w[i]);
		for(int j=0;j<n;j++){scanf("%d",&x);c[i].push_back(x);if(x<c[i][h[i]])h[i]=j;}
	}
	sort(b.begin(),b.end());
	for(int i=1;i<=n;i++) fa[i][0]=i;
	for(int i=0;i<b.size();i++)
	{
		if(tot==n) break;
		if(head(b[i].x)==head(b[i].y))continue;
		fa[b[i].y][0]=b[i].x;fa[b[i].y][1]=b[i].z;tot++;ans+=b[i].z;
	}
	for(int i=1;i<pow(2,k);i++)
	{
		for(int j=1;j<=n;j++) vis[j]=0;vis[head(1)]=1;
		use.clear();
		int t=i,p=1;ll mans=ans;
		while(t!=0){
		if(t%2==1) 
		use.push_back(p);
		p++,t/=2;}
		for(int j:use) mans+=w[j];
		for(int j=1;j<=n;j++)
			if(!vis[j])
			{
				int j1=-1;
				kk=fa[j][1];t1=fa[j][0];
				for(int k:use)
				{
					if(h[k]<0)
						if(kk>c[k][j])
						{
							j1=k;mans-=kk-c[k][j];kk=c[k][j];m1=0;
						}
					else
						{
						if(h[k]!=j&&kk>c[k][j]+c[k][h[k]])
							{
							j1=k;mans-=kk-c[k][j]-c[k][h[k]];kk=c[k][j]+c[k][h[k]];m1=0;
							}
						}
						
					if(h[k]<0)
						if(kk>c[k][t1]&&!vis[t1])
						{
							j1=k;mans-=kk-c[k][t1];kk=c[k][t1];m1=1;
						}
					else
						{
						if(h[k]!=t1&&kk>c[k][t1]+c[k][h[k]]&&!vis[t1])
							{
							j1=k;mans-=kk-c[k][t1]-c[k][h[k]];kk=c[k][t1]+c[k][h[k]];m1=1;
							}
						}
				}
				if(j1!=-1 && h[j1]>=0) h[j1]-=c[j1].size();vis[j]=1;if(m1&&j1!=-1) vis[t1]=1;
			}
		ans=min(ans,mans);
		for(int k:use)
			if(h[k]<0) h[k]+=c[k].size();
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
