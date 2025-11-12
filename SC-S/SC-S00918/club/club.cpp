#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a(114514),b(114514),c(114514);
vector<pair<int ,int>>s(114514);
int ans=0,n;
void dfs(int a1,int b1,int c1,int sum,int idx){
	if(a1>n/2||b1>n/2||c1>n/2)return;
	if(a1+b1+c1==n){
		ans=max(ans,sum);
		return ;
	}
	if(a1+b1+c1>n)return;
	dfs(a1+1,b1,c1,sum+a[idx],idx+1);
	dfs(a1,b1+1,c1,sum+b[idx],idx+1);
	dfs(a1,b1,c1+1,sum+c[idx],idx+1);
}
void solve(){
	int aa=0,bb=0,cc=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];aa+=a[i],bb+=b[i],cc+=c[i];
	}
	if(!bb&&!cc&&n==1e5){
		sort(a.begin(),a.end(),greater<>());
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}cout<<ans;
		return ;
	}
	dfs(0,0,0,0,1);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}