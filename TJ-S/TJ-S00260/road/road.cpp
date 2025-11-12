#include<bits/stdc++.h>
using namespace std;
#define N 1000006
struct csp{
	int u,v,w,bian;
}road[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k!=0){
		int all=0;
		for(int i=0;i<=m;i++){
			cin>>road[i].u>>road[i].v>>road[i].w;
			all+=road[i].w;
		}
		cout<<all;
		return 0;
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>road[i].u>>road[i].v>>road[i].w;
			road[i].bian=i;
		}
		int minn=1e9;
		for(int i=1;i<=m;i++){
			int cost=0;
			bool flag[N],vis[N];
			memset(flag,false,sizeof flag);
			memset(vis,false,sizeof vis);
			for(int j=1;j<=i;j++){
				flag[j]=true;
				cost+=road[j].w;
			}
			for(int j=1;j<=m;j++){
				if(flag[j]){
					vis[road[j].u]=true;
					vis[road[j].v]=true;
					for(int k=1;k<=m;k++){
						if((road[k].u==road[j].u or road[k].u==road[j].v or road[k].v==road[j].u or road[k].v==road[j].v) and flag[k]){
							vis[road[k].u]=true;
							vis[road[k].v]=true;
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				cout<<i<<'\n';
				if(!vis[j]){
					goto gt;
				}
			}
			minn=(minn>=cost?cost:minn);
			gt:continue;
		}
		cout<<minn;
		return 0;
	}
	return 0;
}
