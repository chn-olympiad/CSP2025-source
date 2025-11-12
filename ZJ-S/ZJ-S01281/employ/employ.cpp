#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
char s[505];
int n,m;
int a[505],st[505];
int ans,sum,cnt;
void dfs(int x){
	if(x==n+1){
		if((n-cnt)>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			if(s[x-1]=='0'||cnt>=a[i]) cnt++;
			dfs(x+1);
			st[i]=0;
			if(s[x-1]=='0'||cnt>=a[i]+1) cnt--;
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
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	int p=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0') p=0;
	}
	if(n==m&&p==0){
		cout<<"0";
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
