#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
long long n,m,ans,a[505],vis[505];
string s;
void dfs(int i,int k,int cnt){
	if(i==n){
		if(!(i>0&&(s[i-1]=='0'||cnt>=a[k]))&&n-cnt>=m)ans++;
		if(i>0&&(s[i-1]=='0'||cnt>=a[k])&&n-cnt-1>=m)ans++;
		ans%=Mod;
		return;
	}
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			vis[j]=1;
			if(i>0&&(s[i-1]=='0'||cnt>=a[k]))dfs(i+1,j,cnt+1);
			else dfs(i+1,j,cnt);
			vis[j]=0;
		}
	}
}
long long sqr(int k){
	long long x=1;
	for(int i=1;i<=k;i++)x=x*2%Mod;
	return x;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)k--;
	}
	if(n<=18){
		dfs(0,0,0);
		cout<<ans;
	}else{
		if(k>=m)cout<<sqr(k);
		else cout<<0;
	}
	return 0;
}
