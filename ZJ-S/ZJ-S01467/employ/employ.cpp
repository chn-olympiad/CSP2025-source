#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod=998244353;
ll n,m,ans,num,c[1145];
int a[114],b[114];
string s;
void dfs(int st){
	if(st==n+1){
		int t=0,sum=0;
		for(int i=1;i<=n;i++){
			if(t>=c[a[i]]) t++;
			else if(s[i-1]=='0') t++;
			else sum++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			a[st]=i;
			dfs(st+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++){
		num+=s[i]-'0';
	}
	if(num==n){
		ans=1;
		for(int i=n;i>1;i--) ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	if(m==n) cout<<0,exit(0);
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}


