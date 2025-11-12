#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[100005],d[100005],vis[100005];
long long ans=1e10;
bool canuse[15];
struct ED{
	long long to,val,bel;
};
vector<ED> e[100019];
long long tre(long long s){
	long long sum=0;
	for(int i=0;i<=n;i++){
		d[i]=1e10;
	}
	d[s]=0;
	for(int i=1;i<=n;i++){
		long long u=0;
		for(int v=1;v<=n;v++){
			if(!vis[v]&&d[v]<d[u]){
				u=v;
			}
		}
		sum+=d[u];
		vis[u]=true;
		for(ED t:e[u]){
			if(!vis[t.to]&&d[t.to]>t.val){
				d[t.to]=t.val;
			}
		}
	}
	return sum;
}
long long tre1(long long s){
	long long sum=0;
	for(int i=0;i<=n+k;i++){
		d[i]=1e10;
		vis[i]=false;
	}
	d[s]=0;
	for(int i=1;i<=n+k;i++){
		long long u=0;
		for(int v=1;v<=n+k;v++){
			if(!vis[v]&&d[v]<d[u]){
				u=v;
			}
		}
		sum+=d[u];
		vis[u]=true;
		for(ED t:e[u]){
			if(!canuse[t.bel])continue;
			if(!vis[t.to]&&d[t.to]>t.val){
				d[t.to]=t.val;
			}
		}
	}
	return sum;
}
void dg(long long x,long long excos){
	if(x==k+1){
		ans=min(ans,tre1(1)+excos);
		//cout<<tre1(1)<<endl;
		//cout<<excos+tre1(1)<<endl;
		return;
	}else{
		dg(x+1,excos);
		canuse[x]=1;
		dg(x+1,excos+c[x]);
		canuse[x]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;cin>>u>>v>>w;
		e[u].push_back({v,w,0});
		e[v].push_back({u,w,0});	
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long w;cin>>w;
			e[i+n].push_back({j,w,i});
			e[j].push_back({i+n,w,i});
		}
	}
	if(k==0){
		//cout<<1111111;
		cout<<tre(1);
		return 0;
	}
	else{
		dg(0,0);
		cout<<ans;
		return 0;
	}
	
	return 0;
}

