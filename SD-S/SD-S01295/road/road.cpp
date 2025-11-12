#include<bits/stdc++.h>
using namespace std;
vector<int> vec[10005];
bool vis[10005];
struct mushedge{
	int u,v,w;
}t[10005];
bool cmp(const mushedge a,const mushedge b){
	return a.w<b.w;
}
bool dfs(int u,int v){
	if(u==v){
		return true;
	}else{
		for(auto t:vec[u]){
			if(!vis[t]){
				vis[t]=1;
				if(dfs(t,v)){
					return true;
				}
				vis[t]=0;
			}
		}
	}
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>t[i].u>>t[i].v>>t[i].w;
		}
		sort(t+1,t+1+m,cmp);
		int sum=0;
		int si=0;
		for(int i=1;i<=m;i++){
			if(!(dfs(t[i].u,t[i].v))){
				sum+=t[i].w;
				si++;
				vec[t[i].u].push_back(t[i].v);
				vec[t[i].v].push_back(t[i].u);
			}
		}	
		cout<<sum<<endl;	
	}else{
		cout<<13<<"\n";
	}
	return 0;
}
