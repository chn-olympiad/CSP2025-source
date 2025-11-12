#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[10010],c[1010],a[15][10010];
int find(int x){
	if(x==fa[x])return fa[x];
	else return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	int x=find(a),y=find(b);
	if(x==y)return;
	fa[y]=x;
}
bool cmp(pair<int,pair<int,int> > i,pair<int,pair<int,int> > j){
	return i.first<j.first;
}
vector<pair<int,int> > z[1000010];
vector<pair<int,pair<int,int> > > h;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		z[u].push_back({v,w});
		z[v].push_back({u,w});
		h.push_back({w,{u,v}});
	}
	if(k<=0){
		int ans=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
//			siz[i]=1;
		}
		int cnt=1;
		sort(h.begin(),h.end(),cmp);
		for(auto info:h){
//			h.pop();
			int x=info.first;
			int y=info.second.first;
			int z=info.second.second;
			if(find(y)==find(z)){
				continue;
			}else{
				ans+=x;
				cnt++;
				merge(y,z);
			}
			if(cnt>=n)break;
		}
		cout<<ans<<'\n';
	}else{
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		int minn=1e18;
		for(int i=1;i<(1<<k);i++){
			int as=0;
			vector<pair<int,pair<int,int> > > hh=h;
			for(int j=1;j<=k;j++){
				if(i&(1<<(j-1))){
					as+=c[j];
					for(int kk=1;kk<=n;kk++){
						hh.push_back({a[j][kk],{kk,n+j}});
					}
				}
			}
			for(int i=1;i<=n;i++){
				fa[i]=i;
			}
			int cnt=1;
			sort(hh.begin(),hh.end(),cmp);
			for(auto info:hh){
//				auto info=h.top();
//				h.pop();
				int x=info.first;
				int y=info.second.first;
				int z=info.second.second;
//				if(y<=n&&z<=n)hh.push(info);
				if(find(y)==find(z)){
					continue;
				}else{
					as+=x;
					if(y<=n&&z<=n)cnt++;
					merge(y,z);
				}
				if(cnt>=n)break;
			}
			minn=min(minn,as);
		} 
		cout<<minn<<'\n';
	}
	return 0;
}
