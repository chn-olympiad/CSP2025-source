#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,fa[2000010],b[20],id,cnt,fx,fy,t,m;
ll mi=1e18,ans,a[20][100010],s[20];
struct node{
	int u,v;
	ll w;
}e[2000010],e2[2000010];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&e2[i].u,&e2[i].v,&e2[i].w);
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	while(!b[k+1]){
		id=m;
		ans=0;
		t=n;
		for(int i=1;i<=m;i++) e[i]=e2[i];
		for(int i=1;i<=k;i++)
			if(b[i]){
				ans+=s[i];
				t++;
				for(int j=1;j<=n;j++) e[++id].u=n+i,e[id].v=j,e[id].w=a[i][j];
			}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(e+1,e+1+id,cmp);
		cnt=1;
		for(int i=1;i<=id;i++){
			fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;
			cnt++;
			ans+=e[i].w;
			fa[fx]=fy;
			if(cnt==t) break;
		}
		mi=min(mi,ans);
		b[1]++;
		int w=1;
		while(b[w]==2) b[w]=0,b[++w]++;
	}
	cout<<mi<<endl;
	return 0;
}
