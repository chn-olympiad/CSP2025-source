#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5,MOD=998244353;
int n,a[5010],f[5010];
int dfs(int l,int x,int cnt){
	int ans=0;
	if(x>3&&cnt>a[l-1]*2){
		ans++;
	}
	
	for(int i=l;i<=n;i++){
		ans+=dfs(i+1,x+1,cnt+a[i])%MOD;
		ans%=MOD;
	}
	return ans%MOD;
} 
int cnt=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<dfs(1,1,0);
	return 0;
}

