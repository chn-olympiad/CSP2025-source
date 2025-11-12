#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],dp[1000005],ans;
const int N = 998244353;
void dfs(int id,int m,int cnt){
	if(id==n+1){
		if(cnt>2*m)ans=(ans+1)%N;
		return;
	}
	dfs(id+1,m,cnt);
	dfs(id+1,max(a[id],m),cnt+a[id]);
}
signed main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
