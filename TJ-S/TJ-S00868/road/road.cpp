#include<bits/stdc++.h>
using namespace std;
//n raw n+k new
long long d[20005];
int gl[20005];
int vis[20005];
long long ncos[25],inpv[25];
struct line{
	int v,w;
};
vector<line> mp[20005];
int infro[25];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>inpv[i];
		for(int j=1;j<=n;j++){
			int u=n+i,v=j,w;
			cin>>w;
			mp[u].push_back({v,w});
			mp[v].push_back({u,w});
		}
	}
	int nn=n+k;
	for(int i=0;i<=nn;i++){
		d[i]=1e8;
	}
	for(int i=0;i<=k;i++){
		ncos[i]=inpv[i];
	}
	d[1]=0;
	long long ans=0,trnum=0;
	for(int i=1;i<=nn;i++){
		int u=0;
		for(int j=1;j<=k;j++){
			if(infro[j]) u=j;
		}
		if(u==0) for(int i=1;i<=nn;i++){
			if(!vis[i]&&d[u]+ncos[gl[u]]>d[i]+ncos[gl[i]]){
				u=i;
			}
		}
//		cout<<"vis"<<u<<" "<<d[u]<<endl;
//		cout<<gl[u]<<" "<<ans<<" "<<ncos[gl[u]]<<endl;
		vis[u]=1;
		if(u<=n){
			trnum++;
			ans+=d[u];
//			cout<<"a"<<endl;
		}else{
//			cout<<"b"<<ncos[u-n]<<endl;
			ncos[u-n]+=d[u];
//			cout<<ncos[u-n]<<endl;
		}
		int frp=gl[u];
		if(ncos[frp]){
//			cout<<"from m"<<ncos[frp]<<endl;
			ans+=ncos[frp];
			ncos[frp]=0;
		}
		if(trnum==n) break;
		for(auto l:mp[u]){
			if(!vis[l.v]){
				if(l.v>n&&d[l.v]>l.w){
					d[l.v]=l.w;
					gl[l.v]=0;
					infro[l.v-n]=1;
				}
				if(l.v<=n&&d[l.v]+ncos[gl[l.v]]>l.w+(u>n?ncos[u-n]:0)){
					d[l.v]=l.w;
					if(u>n){
						gl[l.v]=u-n;
					}else{
						gl[l.v]=0;
					}
				}
			}
		}
//		cout<<i<<" ans"<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
