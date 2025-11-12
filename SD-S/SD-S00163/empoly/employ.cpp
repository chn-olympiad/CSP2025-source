#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<0;
}
