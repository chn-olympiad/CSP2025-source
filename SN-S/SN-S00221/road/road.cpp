#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAXN=15e5+10;
int n,m,k,f[MAXN],pz=1,tot;
long long sum=0,ans=2e18;
int c[15];
struct node{
	int u,v;
	int w;
}e[MAXN];
struct ct{
	int c,a[10005];
}mk[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return (x==f[x]?x:f[x]=find(f[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>mk[i].c;
		if(mk[i].c) pz=0;
		for(int j=1;j<=n;j++){
			cin>>mk[i].a[j];
			if(mk[i].a[j]) pz=0;
		}
	}
	if(pz&&k){
		cout<<"0\n";
		return 0;
	}
	if(k==0){
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;
			ans+=e[i].w;
			f[fy]=fx;
		}
		cout<<ans;
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	for(int s=0;s<=(1<<k)-1;s++){
		int tot=0;sum=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int j=1;j<=k;j++){
			if(((s>>(j-1))&1)){
				sum+=mk[j].c;
				for(int i=1;i<=n;i++){
					++tot;
					e[m+tot].u=i,e[m+tot].v=n+j,e[m+tot].w=mk[j].a[i];
				}
			}
		}
		if(sum>ans) continue;
		sort(e+1,e+m+tot+1,cmp);
//		for(int i=1;i<=m+tot;i++){
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
//		}
//		cout<<"\n";
		for(int i=1;i<=m+tot;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;
			sum+=e[i].w;
			if(sum>ans) break;
			f[fy]=fx;
		}
//		cout<<sum<<" "<<ans<<"\n";;
		ans=min(sum,ans);
	}
	cout<<ans;
	return 0;
}
