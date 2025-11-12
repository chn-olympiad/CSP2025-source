#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
int n,m,s[N],c[N],p[N],ans=0;
const int mod=998244353;
bool check(){
	for(int i=1;i<=n;i++){
		if(s[i]!=1)return false;
	}
	return true;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(check()){
		if(n<m)cout<<0<<"\n";
		else{
			int ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)p[i]=i;
	int cnt=0,fail=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1&&fail<c[p[i]])cnt++;
		else if(s[i]==1&&fail>=c[p[i]])fail++;
		else if(s[i]==0)fail++;
	}
	if(cnt>=m)ans++;
	while(next_permutation(p+1,p+n+1)){
		int cnt=0,fail=0;
		for(int i=1;i<=n;i++){
			if(s[i]==1&&fail<c[p[i]])cnt++;
			else if(s[i]==1&&fail>=c[p[i]])fail++;
			else if(s[i]==0)++fail;
		}
		if(cnt>=m)ans++;
		if(ans>=mod)ans-=mod;
	}
	cout<<ans;
	return 0;
}
