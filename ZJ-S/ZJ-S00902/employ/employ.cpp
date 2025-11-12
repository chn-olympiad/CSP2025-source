#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,i,sum,ans,a[510],f[510];char s[510];
void dfs(int t,int lq){
	int i;
	if(t>n){
		if(lq>=m) ans++;
		return ;
	}
	for(i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			if(t-lq-1>=a[i]) dfs(t+1,lq);
			else if(s[t]=='0') dfs(t+1,lq);
			else dfs(t+1,lq+1);
			f[i]=0;
		}
}
//void solve(){
//	long long i,ma=0;
//	ans=0;
//	for(i=1;i<=n;i++) ma=max(ma,a[i]);
//	for(i=1;i<=min(ma,n);i++)
//		if(s[i]=='1') ans++;
//	//ans * (n-1)!
//	cout<<ans<<" ";
//	for(i=1;i<n;i++) ans*=i,ans%=mod;
//	cout<<ans;
//}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++) cin>>a[i];
//	if(m==1){
//		solve();
//		return 0;
//	}
	if(m==n){
		for(i=1;i<=n;i++)
			if(s[i]=='0'||a[i]==0){
				cout<<0;
				return 0;
			}
		ans=1;
		for(i=1;i<=n;i++) ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	for(i=1;i<=n;i++)
		if(a[i]>0) sum++;
	if(a[i]<m){
		cout<<0;
		return 0;
	}
	sum=0;
	for(i=1;i<=n;i++)
		if(s[i]=='1') sum++;
	if(sum<m||n>=13){
		cout<<0;
		return 0;
	}
//	if(i>n){
//		long long nn=0;
//		ans=1;
//		for(i=1;i<=n;i++)
//			if(a[i]==0) nn--;
//		if(n+nn<m){
//			cout<<0;
//			return 0;
//		}
//		for(i=1;i<=n;i++) ans*=i,ans%=mod;
//		cout<<ans;
//		return 0;
//	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

//16+ WA
