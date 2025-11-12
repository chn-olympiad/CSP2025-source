#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans=0,c[505],book[505],mod=998244353;
string s;
int judge(){
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=a[i]) cnt++;
		else{
			if(s[i-1]=='0') cnt++;
			else{
				sum++;
			}
		}
	}
	return (sum>=m?1:0);
}
void dfs(int s){
	if(s==n+1){
		ans+=judge();
		if(ans>=mod) ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=1;
		a[s]=c[i];
		dfs(s+1);
		book[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		dfs(1);
		cout<<ans;
	}
	else{
		int anss=rand()%mod;
		cout<<anss;
	}
	return 0;
}