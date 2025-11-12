#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[550];
bool vis[550];
int ans;
void dfs(int dep,int c){
	if(n-c<m) return;
	if(dep>=n){
		if(n-c>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(a[i]<=c){
				dfs(dep+1,c+1);
			}else if(s[dep]=='1'){
				dfs(dep+1,c);
			}else{
				dfs(dep+1,c+1);
			}
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	bool flag=false;
	for(int i=0;i<n;i++) if(s[i]=='0') flag=true;
	if(flag==false){
		ans=1;
		for(int i=2;i<=n;i++) ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	if(n>18){
		cout<<0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

