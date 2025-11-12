//road
#include<bits/stdc++.h>
using namespace std;
int fa[10005];
int find(int a){
	if(fa[a]==a)return a;
	fa[a]=find(fa[a]);
	return fa[a];
}
struct st{
	int l,a,b;
	friend bool operator<(st x,st y){
		return x.l>y.l;
	}
};
priority_queue<st>G;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(!G.empty()){
		G.pop();
	}
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		G.push({w,u,v});
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	long long ans=0;
	if(k==0){	
		while(!G.empty()){
			if( find(G.top().a)!=find(G.top().b)){
				fa[find(G.top().a)]=find(G.top().b);
				ans+=G.top().l;
			}
			G.pop();
		}
		cout<<ans;
		return 0;
	}
	else{
		int c,A[10005],f;
		for(int i=1;i<=k;i++){
			cin>>c;
			for(int j=1;j<=n;j++){
				cin>>A[j];
				if(A[j]==0)f=j;
			}
			for(int j=1;j<=n;j++)G.push({A[j],f,j});
		}
		while(!G.empty()){
			if( find(G.top().a)!=find(G.top().b)){
				fa[find(G.top().a)]=find(G.top().b);
				ans+=G.top().l;
			}
			G.pop();
		}
		cout<<ans;
		return 0;
	}
	
}


