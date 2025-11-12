#include<bits/stdc++.h>
#define int long long
const int N=8e6+5;
using namespace std;
pair<pair<int,int> ,pair<int,int> >edge[N];
int n,m,k,a[20][N],c[N],cnt;
int ans = 0;
int vis[N];
int fa[N];
//我爱重构，重构让我的生活美好 :) 
int find(int x){
	return fa[x]==x?x:fa[x] = find(fa[x]);
}
int read(){
	int fuc = 0;
	char c;
	while(true){
		c = getchar();
		if(c == ' ' || c=='\n') return fuc;
		fuc *=10;fuc += c-'0';
	}
}
void kk(){
	sort(edge+1,edge+1+cnt);
	for(int i=1;i<=cnt;i++){
		int u = edge[i].second.second,v=edge[i].second.first;
		int w = edge[i].first.first;
		int vs = edge[i].first.second;
		vis[vs]=1;
		int fu = find(u),fv=find(v);
		if(fu == fv) continue;
		ans += w;
		fa[fu] = fv;
//		cout<<i;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m=read(),k=read();
//	cout<<n;
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		u = read(),v=read(),w=read();
		edge[++cnt]={{w,0},{u,v}};		
	}
	for(int i=1;i<=k;i++){
//		scanf("%lld",&c[i]);
		c[i] = read();
		for(int j=1;j<=n;j++){
//			scanf("%lld",&a[i][j]);
			a[i][j] = read();
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int mmin = 0x3f3f3f3f,mp;
			for(int l=1;l<=k;l++){
				if(a[l][i] + a[l][j] < mmin){
					mmin = a[l][i] + a[l][j];
					mp = l;
				}
			}
			edge[++cnt] = {{mmin,mp},{i,j}};
		}
	}
	
//	cout<<"?";
	kk();
	for(int i=1;i<=k;i++){
		if(vis[i]) ans += c[i];
	}
	cout<<ans;
	return 0;
}
