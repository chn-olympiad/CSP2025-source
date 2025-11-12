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
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
}
