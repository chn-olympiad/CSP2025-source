#include <bits/stdc++.h>
using namespace std;
string s;
long long n,m,a[1000010],vis[1000010],t[100010],ans,sum,mod=998244353;
void dfs(int k){
	if(k>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||sum>=a[t[i]])sum++;
		}
		if(sum<=n-m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			t[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum+=s[i]-'0';
	}
	if(sum==n){
		ans=n;
		for(int i=n-1;i>=2;i--)ans=ans*i%mod;
		cout<<ans;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
