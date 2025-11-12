#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[510],ans;
char ch[510];
bool vis[510];
void dfs(int i,int s){
	if(s+n-i+1<m) return;
	if(i>n){
		if(s>=m) ans=(ans+1)%mod;
		return;
	}
	for(int j=1;j<=n;j++){
		if(vis[j]==0){
			vis[j]=1;
			if(i-s-1>=c[j]) dfs(i+1,s);
			else if(ch[i]=='0') dfs(i+1,s);
			else dfs(i+1,s+1);
			vis[j]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
		if(ch[i]=='1') sum++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) sum++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
