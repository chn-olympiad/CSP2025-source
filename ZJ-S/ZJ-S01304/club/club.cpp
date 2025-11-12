#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
int n,a[N][3],b[N][3];
vector<int>g[3];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			cin>>a[i][j];
		for(int j=0;j<3;j++)
			b[i][j]=j;
	}
	for(int i=1;i<=n;i++)
		sort(b[i],b[i]+3,[&](int x,int y){
			return a[i][x]>a[i][y];
		});
	for(int i=0;i<3;i++)g[i].clear();
	for(int i=1;i<=n;i++)
		g[b[i][0]].push_back(i);
	int u=-1;
	if(g[0].size()>n/2)u=0;
	if(g[1].size()>n/2)u=1;
	if(g[2].size()>n/2)u=2;
	ll ans=0;
	for(int i=0;i<3;i++){
		for(auto v:g[i]){
			ans+=a[v][b[v][0]];
		}
	}
	if(u>=0){
		sort(g[u].begin(),g[u].end(),[](int x,int y){
			return a[x][b[x][0]]-a[x][b[x][1]]<a[y][b[y][0]]-a[y][b[y][1]];
		});
		int m=g[u].size()-n/2;
		for(int i=0;i<m;i++){
			int v=g[u][i];
			ans-=a[v][b[v][0]]-a[v][b[v][1]];
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	cin>>_;
	while(_--)solve();

	return 0;
}