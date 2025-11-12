#include <bits/stdc++.h>
#define i64 long long
using namespace std;

const int N = 1e6+10;

bool sttt;
i64 n,m,k;
i64 cnt;
struct Edge{
	i64 u,v,w;
};
vector<Edge> e;

i64 c[15],a[15][N];
i64 fa[N];
bool rp[15];
i64 conn[15];

void init_fa(){
	for(int i=0;i<=n+k+1;i++) fa[i]=i*1ll;
}

i64 find(i64 x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void merge(i64 a,i64 b){
	i64 af=find(a),bf=find(b);
	if(af!=bf) fa[af]=bf;
}

int kruskal(){
	i64 res=0,cnt=0;
	vector<bool> v(n+k+1,0); 
	sort(e.begin(),e.end(),[](auto p,auto q){
		return p.w<q.w;
	});
	for(auto ed:e){
		if(find(ed.u)!=find(ed.v)){
			merge(ed.u,ed.v);
			i64 ct=ed.w;
			if(ed.u>n&&rp[ed.u]) ct-=c[ed.u-n];
			if(ed.v>n&&rp[ed.v]) ct-=c[ed.v-n];
			res+=ct;
//			cout<<ed.u<<' '<<ed.v<<' '<<ct<<endl;
			if(!v[ed.u]){
				v[ed.u]=1;
				if(ed.u<=n) cnt++;
				else rp[ed.u]=1,conn[ed.u]++;
			}
			if(!v[ed.v]){
				v[ed.v]=1;
				if(ed.v<=n) cnt++;
				else rp[ed.v]=1,conn[ed.v]++;
			}
		}
//		cout<<cnt<<endl;
		if(cnt==n) break;
	}
	return res;
}

bool eddd;

int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	init_fa();
//	for(int i=1;i<=n;i++){
//		e.push_back({0,i,0});
//	}
	for(int i=1;i<=m;i++){
		i64 u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}for(int i=1;i<=k;i++){
		cin>>c[i];
//		e.push_back({0,n+i,c[i]});
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
//			e.push_back({n+i,j,a[i][j]});
			e.push_back({n+i,j,c[i]+a[i][j]});
		}
	}i64 ans=kruskal();
	cout<<ans<<endl;
//	cerr<<((int)(&eddd)-(int)(&sttt))/8/1024<<"KB"<<endl;
	return 0;
}
