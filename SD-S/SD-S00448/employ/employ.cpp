#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#define int long long
const int MAXN=505,MOD=998244353;
using namespace std;
int n,m,x;
int ans=1;
string s;
int c[MAXN];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0)x++;
	}
	x=n-x;
	if(x<m){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=1;i<=x;i++){
		ans=(ans*i)%MOD;
	}int f=0;
	if(m==n){
		
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){
				f=1;
				break;
			}
		}
	}
	if(f==1)cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}


