#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int pre[505],a[15],b[15],f[15],n,m,k,ans;
void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[b[i]]>pre[i]) sum++;
		}
		if(sum>=m) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			b[x]=i;
			dfs(x+1);
			f[i]=0;
			b[x]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	k=s.size();
	s=" "+s;
	for(int i=1;i<=k;i++){
		pre[i]=pre[i-1];
		if(s[i]=='0') pre[i]++;
	}
	if(n-pre[n]<m){
		cout<<0;
	}
	else if(pre[n]==0||m==n){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		dfs(1);
	}
	return 0;
}
