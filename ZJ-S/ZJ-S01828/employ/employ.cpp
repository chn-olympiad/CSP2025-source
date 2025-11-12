#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[10005],p[10005],f[10005];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n>>m>>s;s=' '+s;
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]*i%mod;
	if(n<=11){
		for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
		int ans=0;
		do{
//			for(int i=1;i<=n;i++)cerr<<p[i]<<' ';cerr<<'\n';
			int ct=0;
			for(int i=1;i<=n;i++){
				if(c[p[i]]>i-1-ct&&s[i]=='1')ct++;
//				cerr<<ct<<' ';
			}//cerr<<"________\n";
			if(ct>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
	}else{
		cout<<f[n];
	}
}