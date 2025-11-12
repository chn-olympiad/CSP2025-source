#include<bits/stdc++.h>
#define ll long long 
int const maxn=1000;
using namespace std;
ll a,b,c[maxn],n,m,p,q,sum,c0;
string s;
int mod=998244353;
int jie(int x){
	ll res=1;
	for(int i=x;i>1;i--){
		res=res*i%mod;
	}
	return res;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdin);
	cin>>n>>m;
	// 678 1617
	cin>>s;
	for(int i=0;i<s.size();i++){
		sum+=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(sum==n){
		cout<<jie(n)/jie(n-m)%mod;
	}//
	
	return 0;
}
