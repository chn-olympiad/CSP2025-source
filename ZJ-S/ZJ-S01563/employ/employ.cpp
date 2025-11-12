#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int mod=998244353;
const int N=505;
int c[N],ans;
string s;
int b[N],tag[N];
void dfs(int pos){
	if(pos==n+1){
		int fail=0,num=0;
		for(int i=1;i<=n;i++){
			if(fail>=c[b[i]]) fail++;
			else if(s[i]=='1') num++;
			else if(s[i]=='0') fail++;
		}
		if(num>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(tag[i]) continue;
		b[pos]=i;tag[i]=1;
		dfs(pos+1);
		tag[i]=0;b[pos]=0;
	}
}
int fac[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	cin>>s;s=" "+s;for(int i=1;i<=n;i++) cin>>c[i];
	int lose=0;
	for(int i=1;i<=n;i++) if(c[i]==0) lose++;
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	else if(m==n){
		int cnt=0;
		for(int i=1;i<=n;i++) if(s[i]=='1') cnt++;
		if(cnt==n) cout<<fac[n];
		else cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='1') cnt++;
	if(cnt==n){
		
		return 0;
	}
	
	return 0;
}
