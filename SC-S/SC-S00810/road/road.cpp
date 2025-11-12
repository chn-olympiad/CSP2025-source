#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+16,M=1e6+6;
struct good{
	int u,v,w;
}e[M],ee[M];
ll a[16][N],c[16],fa[N];
bool great(good a,good b){
	return a.w<b.w;
}
ll find(ll x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void merge(ll a,ll b){
	fa[find(a)]=find(b);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	ll kk=0,ans=0,sum=0;
	for(int i=1;i<=m;i++)
		cin>>ee[i].u>>ee[i].v>>ee[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(sum==0){
		ll kkk=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				ee[++kkk].u=n+i;
				ee[kkk].v=j;
				ee[kkk].w=a[i][j];
			}
		}
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		sort(ee+1,ee+1+kkk,great);
		for(int i=1;i<=kkk;i++){
			if(find(ee[i].u)==find(ee[i].v))
				continue;
			fa[find(ee[i].u)]=find(ee[i].v);
			ans+=ee[i].w;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(ee+1,ee+1+m,great);
	for(int i=1;i<=m;i++){
		if(find(ee[i].u)==find(ee[i].v))
			continue;
		fa[find(ee[i].u)]=find(ee[i].v);
		e[++kk].u=ee[i].u;
		e[kk].v=ee[i].v;
		e[kk].w=ee[i].w;
		ans+=ee[i].w;
	}
	for(int i=0;i<=(1<<k)-1;i++){
		for(int j=1;j<=kk;j++)
			ee[j]=e[j];
		ll k2=kk,anss=0;
		for(int j=1;j<=k;j++)
			if(((1<<(j-1))&i)>0){
				for(int l=1;l<=n;l++)
					ee[++k2].u=n+j,ee[k2].v=l,ee[k2].w=a[j][l];
				anss+=c[j];
			}
		for(int j=1;j<=n+k;j++)
			fa[j]=j;
		sort(ee+1,ee+1+k2,great);
		for(int j=1;j<=k2;j++){
			if(find(ee[j].u)==find(ee[j].v))
				continue;
			anss+=ee[j].w;
			merge(ee[j].u,ee[j].v);
		}
		ans=min(anss,ans);
	}
	cout<<ans;
	return 0;
}
