#include<bits/stdc++.h>//CSP-S2025 RP++
#define int long long
using namespace std;
int n,m,k,c[20],ans,g[1009][1009],id[10009],val[12][10009];
vector<int> d[12];
struct node{
	int u,v,w;
}a[3000009];
bool cmp(node xxx,node yyy){
	return xxx.w<yyy.w; 
}
int find(int x){
	return (id[x]==x) ? x : (id[x]=find(id[x]));
}
void unite(int x,int y){
	int rx=find(x),ry=find(y);
	id[rx]=ry;
	find(x);
	find(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		id[i]=i;
	}
	if(k){
		memset(g,0x3f,sizeof(g));
		for(int i=1;i<=m;++i){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		for(int i=1;i<=k;++i){
			cin>>c[i];
			for(int j=1;j<=n;++j){
				cin>>val[i][j];
				if(!val[i][j]){
					d[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=k;++i){
			for(int j : d[i]){
				for(int l=1;l<=n;++l){
					a[++m]={j,l,val[i][j]+val[i][l]};
				}
			}
		}
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;++i){
			if(id[a[i].u]!=id[a[i].v]){
				++cnt;
				ans+=a[i].w;
				unite(a[i].u,a[i].v);
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=m;++i){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;++i){
			if(id[a[i].u]!=id[a[i].v]){
				++cnt;
				ans+=a[i].w;
				unite(a[i].u,a[i].v);
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
	}
	return 0;//return whk
}
//1
//1
//4
//5
//1
//4
