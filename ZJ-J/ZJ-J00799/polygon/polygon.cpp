#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int MOD=998244353;
unordered_map<string,bool> vis;
void dfs(int x,int sum,int maxn,int cnt,string pos) {
	if(sum>maxn*2 and cnt>=3 and !vis[pos]) {
		ans++;
		if(ans>=MOD)ans-=MOD;
		vis[pos]=1;
	}
	if(x>n)return;
	dfs(x+1,sum,maxn,cnt,pos);
	dfs(x+1,sum+a[x],max(maxn,a[x]),cnt+1,pos+to_string(x));
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,0,0,0,"");
	cout<<ans;
	return 0;
}

