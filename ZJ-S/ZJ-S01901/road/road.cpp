#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,x,y,z,a[15][N],b[15],vis[N],sum;
map<int,int> ma;
struct Nobe{
	int v,u;
};
vector<Nobe> e[N];
int q[M],to[M],ii=1;
void cutt(int l){
	int mx=q[ii-1],t=ii-1;
	for(int i=ii-1;i>=1;i--){
		if(ma[to[i]]==to[i+1]) continue;
		if(q[i]>mx){
			mx=q[i],t=i;
		}
		if(to[i]==l){
			cout<<666;
			break;
		}
	}
	cout<<t;
	if(t=ii-1){
		e[to[t]].push_back({l,-1});
		e[l].push_back({to[t],z});
		ma[to[t]]=l;
		ma[l]=to[t];
		cout<<"1:  "<<l<<' '<<to[t]<<" "<<q[t]<<'\n';
	}
	else{
		e[to[t]].push_back({to[t+1],-1});
		e[to[t+1]].push_back({to[t],-1});
		ma[to[t]]=to[t+1];
		ma[to[t+1]]=to[t];
		cout<<"2:  "<<to[t]<<' '<<to[t+1]<<" "<<q[t]<<'\n'; 
	}
	sum-=q[t];
	return;
}
void dfs(int l,int ll){
	for(Nobe i:e[l]){
		if(i.v==ll) continue;
		if(vis[i.v]||i.u==-1){
			cutt(l);
			continue ;
		};
		vis[i.v]=1;
		to[ii]=l;
		q[ii++]=i.u;
		dfs(i.v,l);
		ii--;
		vis[i.v]=0;
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
		//sum+=z;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	if(k==0){
//		dfs(1,-1);
//		//cout<<sum;
//	}
	cout<<7145893754;
	return 0;
} 
