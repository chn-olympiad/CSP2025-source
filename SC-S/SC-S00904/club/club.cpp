#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll ans,n;
struct Node{
	int a,b,c;
}t[N];
void dfs(int u,int x,int y,int z,ll su){
	if(u==n+1){
		ans=max(ans,su);
	}
	if(x<n/2) dfs(u+1,x+1,y,z,su+t[u].a);
	if(y<n/2) dfs(u+1,x,y+1,z,su+t[u].b);
	if(z<n/2) dfs(u+1,x,y,z+1,su+t[u].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}