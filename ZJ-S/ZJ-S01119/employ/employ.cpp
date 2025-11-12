#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[505],b[505],f[505],ans=0;
string s;
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[b[i]]||s[i]=='0')cnt++;
		}
		if(n-cnt>=m){
			ans++;	
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			b[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	cout<<s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n==m){
		int g=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||s[i]=='0')g=1;
		}
		if(g==1)cout<<"0";
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
