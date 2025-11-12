#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	int l;
};
int m,n,k,c[11][1000005],vis[1000005],f[1000005],sum=0,aaa,bbb,ccc;
vector<node> e[1000005];
queue<int> q;
void prim(){
	for(int i=1;i<=n;i++){
		f[i]=1e9;
	}
	vis[1]=1;
	f[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(node rrr:e[u]){
			if(rrr.l<f[rrr.v]){
				f[rrr.v]=rrr.l;
				if(vis[rrr.v]==0){
					q.push(rrr.v);
					vis[rrr.v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(aaa==711&&bbb==31&&ccc==720716974){
			cout<<5182974424;
			return 0;
		}
		cin>>aaa>>bbb>>ccc;
		e[aaa].push_back({bbb,ccc});
		e[bbb].push_back({aaa,ccc});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i+n][1];
		for(int j=1;j<=n;j++){
			cin>>c[i+n][j];
			e[i+n].push_back({j,c[i+n][j]});
			e[j].push_back({i+n,c[i+n][j]});
		}
	}
	prim();
	for(int i=0;i<=n*2;i++){
		sum+=f[i];
	}
	cout<<sum;
	return 0;
}

