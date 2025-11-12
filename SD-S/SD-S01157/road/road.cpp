#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
int n,m,k,ans;
bool f[maxn];
struct node{
	int u,v,w;
}edge[maxn];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
		    int u,v,w;
		    cin>>u>>v>>w;
		    edge[i].u=u;
		    edge[i].v=v;
		    edge[i].w=w;
	    }
	    sort(edge+1,edge+m+1,cmp);
	    int sum=n;
	    for(int i=1;i<=m;i++){
		    if(sum==0)break;
		    if(f[edge[i].u]==0&&f[edge[i].v]==0)sum-=2,ans+=edge[i].w,f[edge[i].v]=f[edge[i].u]=1;
		    else{
			    if(f[edge[i].u]==0)sum--,ans+=edge[i].w,f[edge[i].u]=1;
			    if(f[edge[i].v]==0)sum--,ans+=edge[i].w,f[edge[i].v]=1;
		    }
	    }
	    cout<<ans;	
	} 
	return 0;
}

