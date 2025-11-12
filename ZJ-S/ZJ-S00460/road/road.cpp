#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10,M=2e4+10;
ll n,m,k,ans,cnt,c[20],vs[20],fa[M];
struct node{
	ll u,v,w,vis,t;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
ll find(int x){
	if(fa[x]==x) return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
ll kruskal(){
	for(int i=1;i<=cnt;i++) fa[i]=i;
	ll ret=0,s=n;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<s;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y){
			s++;
			continue;
		}
		fa[find(a[i].u)]=y;
		ret+=a[i].w;
		if(a[i].vis&&!vs[a[i].t]){
			vs[a[i].t]=1;
			ret+=c[a[i].t];
			s++;
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].vis=0;
	}
	cnt=m;
	ans=kruskal();
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int p;
			cin>>p;
			a[++cnt].u=n+i;
			a[cnt].v=j;
			a[cnt].w=p;
			a[cnt].vis=1;
			a[cnt].t=i;
		}
		ans=min(ans,kruskal());
	}
	cout<<ans<<endl;

	return 0;
}