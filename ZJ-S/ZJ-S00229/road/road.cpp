#include<bits/stdc++.h>
#define mp make_pair
#define int long long
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool f=0;
	while(c<'0'||c>'9'){f=(f||(c=='-'));c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}
vector<pair<int,int> >ve[10005];
vector<pair<int,int> >ve_countryside[20];
int c[20];
int n,m,k;
int ansAtLast=0x3f3f3f3f3f3f3f3f;

int isoc[20];//isOpenCountryside
int ans=0;

struct node{
	int u,v;
	bool operator<(const node& other)const {
		return v>other.v;
	}
};
priority_queue<node>pq;
int d[10005];
int vis[10005];
int dcs[10005];
bool viscs[10005];

void dij_road(){
	while(pq.size()) pq.pop();
	pq.push({1,0});
	for(int i=1;i<=n;i++){
		d[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	for(int i=1;i<=k;i++){
		dcs[i]=0x3f3f3f3f3f3f3f3f;
		viscs[i]=0;
	}
	d[1]=0;
//	cout<<"go go go";
	while(pq.size()){
		node tmp=pq.top();
//		cout<<"tmp"<<tmp.u<<' '<<tmp.v<<endl;
		pq.pop();
		if(tmp.u>0){
			if(vis[tmp.u]) continue;
			vis[tmp.u]=1;
			ans+=tmp.v;
			for(auto x:ve[tmp.u]){
				int u=x.first;int v=x.second;
				if(u>0){
					if(v>=d[u]||vis[u]) continue;
					d[u]=v;
					pq.push({u,v});
				}
				else{
					u=-u;
					if(v>=dcs[u]||viscs[u]||!isoc[u]) continue;
					dcs[u]=v;
					pq.push({-u,v});
				}
			}
		}
		else{
			tmp.u=-tmp.u;
			if(viscs[tmp.u]) continue;
			viscs[tmp.u]=1;
			ans+=tmp.v;
			for(auto x:ve_countryside[tmp.u]){
				int u=x.first;int v=x.second;
				if(v>d[u]||vis[u]) continue;
				d[u]=v;
				pq.push({u,v});
			}
		}
	}
}
void dfs(int x){
	if(x==k+1){
		ans=0;
		for(int i=1;i<=k;i++){
			if(isoc[i]) ans+=c[i];
		}
		dij_road();
		ansAtLast=min(ansAtLast,ans);
		return ;
	}
	isoc[x]=0;dfs(x+1);
	isoc[x]=1;dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int x,y,w;
		x=read();y=read();w=read();
		ve[x].push_back(mp(y,w));
		ve[y].push_back(mp(x,w));
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			ve[j].push_back(mp(-i,x));
			ve_countryside[i].push_back(mp(j,x));
//			if(i==1&&j==2) cout<<"OK"<<x<<"}"<<endl;
		}
	}
	dfs(1);
	printf("%d",ansAtLast);
	return 0;
}
/*
0<=k<=10!!!!
*/
