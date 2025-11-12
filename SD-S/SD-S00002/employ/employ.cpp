#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
char s[10111]; 
int c[10101];
long long n,m,ans;
int vis[10101],p[10101];
bool check(){
	int fal=0,sum=0;
	for(int i=1;i<=n;i++){
		if(fal>=c[p[i]]){
			fal++;
			continue;
		}
		if(s[i]=='0'){
			fal++;
			continue;
		}
		if(s[i]=='1')	sum++;
	}
	if(sum>=m){
//		for(int i=1;i<=n;i++){
//			cout<<p[i];
//		}
		return true;
	}	
	return false;
}
void dfs(int now){
	if(now>n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10&&m<=10){
		dfs(1);
		ans%=mod;
		cout<<ans;
	}
	else if(n==m){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				cout<<0;
				return 0;
			} 
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		int re=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				re--;
			} 
		}
		if(re<m){
			cout<<0;
			return 0; 
		}
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}

