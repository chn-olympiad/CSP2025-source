#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],js,vis[505];
long long cnt[505];
string s;
long long ans;
void dfs(int day,int jj,int sum){
	if(day>=n){
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int op=0,pp=1;
			if(jj>=a[i]||s[day]=='0') op=1,pp=0;
			dfs(day+1,op+jj,sum+pp);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]=='1') js++;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(js==n){
		cnt[0]=1;
		int sum=0;
		for(int i=n;i>=1;i--){
			sum++;
			cnt[sum]=(cnt[sum-1]*i)%mod;
		}
		for(int i=m;i<=n;i++){
			ans=(ans%mod+cnt[i]%mod)%mod;
		}
		cout<<ans;
	}else{
		dfs(0,0,0);
		cout<<ans%mod;
	}
	return 0;
}
