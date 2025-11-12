#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10,M=1e4+10;
int n,m,k,a[20][M],c[20],fa[N];
struct node{
	int u,v;
	ll w;
}edge[N*2],e1[N*2];
bool cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool f=1,f1=0;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) f1=1;
		} 
	} 
	if(k==0){
		sort(edge+1,edge+1+m,cmp);
		ll ans=0,cnt=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int u=edge[i].u,v=edge[i].v;
			ll w=edge[i].w;
			int t1=find(u),t2=find(v);
			if(t1==t2) continue;
			fa[t1]=t2;
			cnt++;
			ans+=w;
			if(cnt==n-1) break;
		}
		cout<<ans;
		return 0;
	}
	if(f && f1){
		int tot=m,nn=n;
		for(int i=1;i<=k;i++){
			nn++;
			for(int j=1;j<=n;j++)
				edge[++tot]={nn,j,a[i][j]};
		}
		sort(edge+1,edge+1+tot,cmp);
		for(int i=1;i<=nn;i++) fa[i]=i;
		int cnt=0;
		ll ans=0;
		for(int i=1;i<=tot;i++){
			int u=edge[i].u,v=edge[i].v;
			ll w=edge[i].w;
			int t1=find(u),t2=find(v);
			if(t1==t2) continue;
			fa[t1]=t2;
			cnt++;
			ans+=w;
			if(cnt==nn-1) break;
		}
		cout<<ans;
		return 0;
	}
	ll minn=1e18;
	for(int i=0;i<(1<<k);i++){
		ll ans=0;
		int tot=m,nn=n;
		for(int j=1;j<=m;j++) e1[j]=edge[j]; 
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				nn++;
				ans+=c[j];
				for(int d=1;d<=n;d++) e1[++tot]={nn,d,a[j][d]};
			}
		}
		sort(e1+1,e1+1+tot,cmp);
		for(int i=1;i<=nn;i++) fa[i]=i;
		int cnt=0;
		for(int i=1;i<=tot;i++){
			int u=e1[i].u,v=e1[i].v;
			ll w=e1[i].w;
			int t1=find(u),t2=find(v);
			if(t1==t2) continue;
			fa[t1]=t2;
			cnt++;
			ans+=w;
			if(cnt==nn-1) break;
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}
