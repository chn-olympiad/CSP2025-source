#include<bits/stdc++.h>
#define ll long long
 
using namespace std;

const int maxn=1e9;

int n,m,k;
struct Edge{
	int u,v,w;
	friend bool operator<(Edge a,Edge b){
		return a.w<b.w;
	}
}e[5000005];int cnt=0;
int ne[15][10005];
int f[10005];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	f[x]=y;
}
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}
map<pair<int,int>,int> mp;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+1+m);
		init(n);
		int cnt=0,ans=0;;
		for(int i=1;i<=m;i++){
			if(cnt==n-1)break;
			int u=e[i].u,v=e[i].v,w=e[i].w;
			u=find(u),v=find(v);
			if(u==v)continue;
			merge(u,v);
			ans+=w;
			cnt++;
		}
		cout<<ans;
		return 0;
	}else{
		int flg=1;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[i].u=u;e[i].v=v;e[i].w=w;
			if(e[i].u<e[i].v)swap(e[i].u,e[i].v);
			mp[{e[i].u,e[i].v}]=e[i].w;
		}
		for(int i=1;i<=k;i++){
			int c;
			cin>>c;
			if(c!=0)flg=0;
			for(int j=1;j<=n;j++){
				cin>>ne[i][j];
			}
		}
		if(flg){
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					for(int l=1;l<j;l++){
						if(mp.count({j,l})==0||mp[{j,l}]>ne[i][j]+ne[i][l]){
							mp[{j,l}]=ne[i][j]+ne[i][l];
//							cout<<i<<" "<<j<<" "<<l<<" "<<mp[{j,l}]<<"\n";
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					e[++cnt]={i,j,mp[{i,j}]};
//					cout<<i<<" "<<j<<" "<<mp[{i,j}]<<" ";
//					cout<<e[cnt].u<<" "<<e[cnt].v<<" "<<e[cnt].w<<"\n";
				}
			}
//			cout<<cnt<<"\n\n";
			sort(e+1,e+1+cnt);
			init(n);
			int ct=0,ans=0;;
			for(int i=1;i<=cnt;i++){
				if(ct>=n-1)break;
				int u=e[i].u,v=e[i].v,w=e[i].w;
				int fu=find(u),fv=find(v);
				if(fu==fv)continue;
				merge(fu,fv);
				ans+=w;
				ct++;
//				cout<<u<<" "<<v<<" "<<w<<"\n";
			}
			cout<<ans;
			return 0;
		}else{
			
			sort(e+1,e+1+m);
			init(n);
			int cnt=0,ans=0;;
			for(int i=1;i<=m;i++){
				if(cnt==n-1)break;
				int u=e[i].u,v=e[i].v,w=e[i].w;
				u=find(u),v=find(v);
				if(u==v)continue;
				merge(u,v);
				ans+=w;
				cnt++;
			}
			cout<<ans;
		}
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/

