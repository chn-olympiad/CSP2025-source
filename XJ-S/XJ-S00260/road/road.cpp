#include <bits/stdc++.h>
using namespace std;
long long n,m,k,f[10000+5],c[1000000+5],b[1000000+5];
struct node {
	int u,v,w;
}a[1000000+5];
struct node1{
	int c,b[10000+5];
}an[10+5];
bool cmp(node x,node y){
	if(x.w==y.w)return x.u<y.u;
	return x.w<y.w;
}
bool cmp1(node1 x,node1 y){
	return x.c<y.c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int k1[10000+4];
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
	}
	for(int j=1;j<=k;j++)
	{
		cin>>an[j].c;
		for(int i=1;i<=n;i++){
			cin>>an[j].b[i];
			if(an[j].c==0&&an[j].b[i]==0)f[a[i].u]=f[a[i].v]=1; 
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				if(an[j].b[i]>an[j].b[k])swap(an[j].b[i],an[j].b[k]);
			}
		}
	}
	sort(an+1,an+k+1,cmp1);
	sort(a+1,a+n+1,cmp);
	f[a[1].u]=1;
	f[a[1].v]=1;
	ans+=a[1].w;
	int tt=0;
	for(int i=2;i<=n;i++){
		if(f[a[i].u]&&!f[a[i].v])
		{
			if(!f[a[i].v]){
				int tx=an[1].b[a[i].v]+an[1].b[a[i].u];
				if(k1[a[i].v]==1)tx-=an[1].b[a[i].v];
				if(k1[a[i].u]==1)tx-=an[1].b[a[i].u];
				if(a[i].w>tx)tt=1,ans+=tx,f[a[i].v]=1,k1[a[i].v]=1,k1[a[i].u]=1;
				else f[a[i].v]=1,ans+=a[i].w;
			}
		}
		if(f[a[i].v]&&f[a[i].u]){
			if(!f[a[i].u]){
				int tx=an[1].b[a[i].v]+an[1].b[a[i].u];
				if(k1[a[i].v]==1)tx-=an[1].b[a[i].v];
				if(k1[a[i].u]==1)tx-=an[1].b[a[i].u];
				if(a[i].w>tx)tt=1,ans+=tx,f[a[i].u]=1,k1[a[i].v]=1,k1[a[i].u]=1;
				else f[a[i].u]=1,ans+=a[i].w;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=1&&!k1[i]){
			ans+=an[1].b[i];
		}
	}
	if(tt)ans+=an[1].c;
	cout<<ans;
	return 0;
}
