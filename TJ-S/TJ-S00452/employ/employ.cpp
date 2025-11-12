#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
const int N=507;
int n,m;
string s;
int c[N];
bool vis[N];
int ans;
void dfs(int num,int fail){
	if(num==n+1){
		if(fail<=n-m){
			++ans%Mod;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		if(s[num-1]=='0' || fail>=c[i]){
			vis[i]=true;
			dfs(num+1,fail+1);
			vis[i]=false;
		}
		else{
			vis[i]=true;
			dfs(num+1,fail);
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i-1]=='1')++cnt;
		cin>>c[i];
	}
	dfs(1,0);
	if(cnt<m){
		cout<<"0";
		return 0;
	}
	cout<<ans%Mod;
	return 0;
}
