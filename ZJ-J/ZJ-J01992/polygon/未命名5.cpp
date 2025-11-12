#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=2e3+10;
const int inf=1e17;
const int mod=998244353;
int ksm(int a,int b){
	if(b==1){
		return a;
	}
	if(b%2==0){
		return ksm(a,b/2)*ksm(a,b/2)%mod;
	}
	if(b%2==1){
		return ksm(a,b/2)*ksm(a,b/2)%mod*a%mod;
	}
}
int ps[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int ans=0;
	ps[0]=1;
	for(int i=1;i<=5000;i++){
		ps[i]=ps[i-1]*i%mod;
//		cout<<i<<":"<<ps[i]<<' ';
	}
	for(int i=3;i<=5000;i++){
		ans+=ps[5000]*ksm(ps[5000-i],mod-2)%mod*ksm(ps[i],mod-2)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}

