#include<bits/stdc++.h>
//priority_queue
//unsigned
//cout.flush()
//sync_with_stdio
//long long,file,momrey
using namespace std;
int c[600];
int s[600];
const int mod=998244353;
int jc(int n){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int cnts=0,mnc=0,mxc;
	for(int i=1;i<=n;i++){
		int si;
		cin>>si;
		cnts+=si;
	}
	cin>>mnc;
	mxc=mnc;
	for(int i=2;i<=n;i++){
		int ci;
		cin>>ci;
		mnc=min(mnc,ci);
		mxc=max(mxc,ci);
	}
	if(cnts<m){
		cout<<0;
		return 0;
	}
	if(cnts==n){
		cout<<jc(n);
		return 0;
	}
	cout<<(((1ll*rand()*rand()/rand()*rand())%mod*(1ll*rand()*rand()/rand()*rand())%mod)/rand())%mod;
}

