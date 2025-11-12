#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
int n,a[N][3],f[N],aa[N];
bool a23=1;
unordered_map<int,bool>vis;
void dfs(int dep,int x,int y,int z,int s){
	if(dep>n+1) return ;
	if(x>n/2) return ;
	if(y>n/2) return ;
	if(z>n/2) return ;
	f[dep-1]=max(f[dep-1],s);
	//cout<<dep<<":"<<x<<" "<<y<<" "<<z<<"\n";
	dfs(dep+1,x+1,y,z,s+a[dep][1]);
	dfs(dep+1,x,y+1,z,s+a[dep][2]);
	dfs(dep+1,x,y,z+1,s+a[dep][3]);
}
void solve(){
	cin>>n;a23=1;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0) a23=0;
		if(a[i][3]!=0) a23=0;
		if(a23) aa[i]=a[i][1];
		f[i]=max({a[i][1],a[i][2],a[i][3]});
	}
	if(a23){
		int ans=0;
		sort(aa+1,aa+n+1);
		for(int i=n;i>n/2;i--){
			ans+=aa[i];
		}
		cout<<ans<"\n";
		return ;
	}
	dfs(1,0,0,0,0);
	//for(int i=1;i<=n;i++){
	//	cout<<f[i]<<" ";
	//}
	cout<<f[n]<<"\n";
}
int t;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
