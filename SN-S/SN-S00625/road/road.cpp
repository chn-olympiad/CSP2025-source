#include<bits/stdc++.h>// 董柏辰 SN-S00625 西安铁一中滨河高级中学 
using namespace std;
#define ll long long
int m,n,k,vis[10010][10010];
ll ans;
struct Node{
	ll co;
	ll u;
	ll v;
}dbc[1000010];
bool cmp(Node x,Node y){
	return x.co<y.co;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		cin>>dbc[i].u>>dbc[i].v>>dbc[i].co;
	    
	    sort(dbc+1,dbc+1+m,cmp);
	    for(int j=1;j<=m;j++){
	    	if(vis[dbc[j].u][dbc[j].v]||vis[dbc[j].v][dbc[j].u])continue;
	    	else {
	    		vis[dbc[j].u][dbc[j].v]=vis[dbc[j].v][dbc[j].u]=1;
	    		ans+=dbc[j].co;
	    		
			}
		}
	cout<<ans;
	return 0;
}

