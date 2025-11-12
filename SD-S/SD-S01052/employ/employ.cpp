//T4
#include<iostream>
#include<cstdio>
using namespace std;
const int N=505,Mod=998244353;
bool d[N],vis[N];
int a[N];
int n,m;
int ans;
void dfs(int r,int cnt,int res){
	if(r==n+1){
		if(res>=m)
			ans++,ans%=Mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		dfs(r+1,cnt+(cnt>=a[i]||!d[r]),res+(cnt<a[i]&&d[r]));
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) d[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>a[i];
	
	dfs(1,0,0);
	cout<<ans<<endl;

	return 0;
}

