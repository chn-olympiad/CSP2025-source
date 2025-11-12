#include<bits/stdc++.h>
//#include<windows.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int const M=5e5+10;
int a[M];
int n,k;
int ans=0;
void dfs(int s,int su){
//	cout<<s<<" "<<su<<endl;
	if(su==k){
		ans++;
		dfs(s+1,a[s]);
	}
	if(s==n+1)return;
	if(su==-1)dfs(s+1,a[s]);
	else dfs(s+1,su^a[s]);
	dfs(s+1,-1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(2,a[1]);
	cout<<ans<<endl;
}
signed main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
