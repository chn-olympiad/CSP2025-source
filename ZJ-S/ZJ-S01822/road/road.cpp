#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MAX;
struct node{
	int to,num;
};
vector<node> v[10003];
bool f[10003];
void dfs(int now,int sum){
	if(sum>=ans)return;
	bool k=1;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			k=0;
			break;
		}
	}
	if(k==1){
		ans=min(ans,sum);
		return;
	}
	for(auto t:v[now]){
		if(f[t.to]==0){
			f[t.to]=1;
			dfs(t.to,sum+t.num);
			f[t.to]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int U,V,W;
		cin>>U>>V>>W;
		v[U].push_back({V,W});
		v[V].push_back({U,W});
	}
	f[1]=1;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
