#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define int long long
int fa[10005],cc[100005];
struct t{
	int u;
	int v;
	int w;
}e[1000005];
struct mk{
	int k;
	int id;
}h[10005];
bool d[10005][10005];
bool dddd[10005][10005];
int dep[10005];
vector<pair<int,int> >dd[10005];
vector<int >ddd;
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int hh[15];
bool cmp(t a,t b){
	return a.w<b.w;
}
bool cmp1(mk a,mk b){
	return a.k<b.k;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,kkk;
	cin>>n>>m>>kkk;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w; 
		if(e[i].u>e[i].v){
			swap(e[i].u,e[i].v);
		}
	}
	
	sort(e+1,e+1+m,cmp);
	int ans=0;
	int kk=0;
	
	for(int i=1;i<=m;i++){
	
		int x=find(e[i].u);
			int y=find(e[i].v);
		if(x>y){
			swap(x,y);
		}
		if(x!=y){
			fa[x]=y;
			ans+=e[i].w;
			
			d[e[i].u][e[i].v]=1;
			//cout<<e[i].w<<" "<<e[i].v<<endl;
			d[e[i].v][e[i].u]=1;
			//cout<<x<<" "<<y<<endl;
			dd[e[i].u].push_back({e[i].v,e[i].w});
			dd[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
	
	for(int i=1;i<=kkk;i++){
		cin>>hh[i];
		for(int j=1;j<=n;j++){
			fa[j]=j;
			cin>>h[j].k;
			h[j].id=j;
			cc[j]=h[j].k;
		}
		int jj=ans;
		for(auto j:dd[i]){
			if(d[j.first][i]){
				dddd[i][j.first]=1;
				dddd[j.first][i]=1;
				d[i][j.first]=0;
				d[j.first][i]=0;
				jj-=j.second;
			}
		}
		jj+=hh[i]+h[i].k;
		//dd[i].clear();
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			for(auto u:dd[j]){
				//cout<<d[u.first]<<" "<<i<<" "<<jendl;
				if(u.first==i||(d[u.first][j]==0&&d[j][u.first]==0)){
					//dd[j].erase();
					continue;
				}
				//cout<<j<<" "<<u.first;
				int x=find(j);
				int y=find(u.first);
				if(x>y){
					swap(x,y);
				}
				if(x!=y){
					fa[x]=y;
				}
			}
		}
		//cout<<fa[1]<<" "<<fa[2]<<" "<<fa[3]<<" "<<fa[4]<<endl;
		sort(h+1,h+1+n,cmp1);
		for(int j=1;j<=n;j++){
			if(i==h[j].id){
				continue;
			}
			int x=find(i);
			int y=find(h[j].id);
			if(x>y){
				swap(x,y);
			}
			if(x!=y){
				fa[x]=y;
				jj+=h[j].k;
				//cout<<h[j].k<<" "<<h[j].id<<endl;
				d[i][h[j].id]=1;
				d[h[j].id][i]=1;
				//dep[j]=h[j];
				ddd.push_back(h[j].id);
				//ddd.push_back(i);
			}
			//cout<<jj<<endl;
		}
		if(jj<ans){
			dd[i].clear();
			for(int j=1;j<=n;j++){
				if(d[i][j]){
					dd[i].push_back({j,cc[j]});
					dd[j].push_back({i,cc[j]});
				}
			}
			ans=jj;
		}
		else{
			for(auto kk:ddd){
				d[i][kk]=0;
				d[kk][i]=0;
			}
			for(auto kk:dd[i]){
				if(dddd[kk.first][i]){
				d[kk.first][i]=1;
				d[i][kk.first]=1;
			}
			}
		}
		ddd.clear();
		//int jj;
		//cout<<ans<<" "<<jj<<endl;
		for(int j=1;j<=n;j++){
			dddd[i][j]=0;
			dddd[j][i]=0; 
		}
	}
	cout<<ans<<endl;
	return 0;
}

