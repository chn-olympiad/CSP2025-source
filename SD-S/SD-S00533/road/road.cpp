#include<bits/stdc++.h>
#define IXcape cout<<endl;return 0
#define Venti cout<<"\nVenti!\n"
#define int long long
using namespace std;
const int V=1e4+20,E=1e6+10;
int n,m,k,ans;
int e[E<<1],ne[E<<1],h[V],w[E<<1],idx=2;
bool vis[V];

inline
void add(int a,int b,int val){
	e[idx]=b,ne[idx]=h[a],w[idx]=val,h[a]=idx++;
}

priority_queue<int,vector<int>,greater<int>>q;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
		add(v,u,val);
		ans+=val; 
	}
	for(int i=1;i<=k;i++){
		int c,val;
		cin>>c;
		for(int u=1;u<=n;i++){
			cin>>val;
			add(n+i,u,val);
			add(u,n+i,val);
		}
	}
	
	cout<<ans;
	IXcape;
}
/*
这里是无风的烬寂海啊…… 
*/

