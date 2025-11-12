#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int const mod=998244353;
int n;
int a[5010];
bool vis[5010];
int num[5010];
int ans=0;
//vector<int>v;
void dfs(int s,int maxn,int sum){
	if(sum>maxn*2){
//		for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
//		cout<<endl;
		ans=(ans+1)%mod;
	}
	if(s==n+1)return;
	for(int i=s;i<=n;i++){
		if(vis[i])continue;
		if(a[i]>=num[s-1]){
			vis[i]=1;
			num[s]=a[i];
//			v.push_back(i);
			dfs(s+1,max(maxn,a[i]),sum+a[i]);
//			v.pop_back();
			vis[i]=0;
			num[s]=0;
		}
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
