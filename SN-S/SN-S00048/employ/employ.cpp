#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define int long long
#define mod 998244353
#define mem(i,o) memset(i,o,sizeof i)
#define rep(i,o,n) for(int i=o;i<=n;i++)
#define dep(i,o,n) for(int i=o;i>=n;i--)

const int N = 0;
int n,m;
char t[510];
int a[510];
int c[510];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int x=1;
	rep(i,1,n) cin>>t[i],x=min(x,(int)(t[i]-'0'));
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	if(x==1){
		int f=0; 
		rep(i,1,n)f+=bool(a[i]);
		if(f<m){
			cout<<0;
		} else{
			int ans = 1;
			rep(i,1,n) ans=(ans*i)%mod;
			cout<<ans<<endl;
		}
	}
}

