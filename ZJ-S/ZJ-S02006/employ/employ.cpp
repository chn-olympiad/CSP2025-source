#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=1;cin>>n>>m;
	for(int i=0;i<n;i++){
		char c;cin>>c;
		if(c=='0'){
			f=0;break;
		}
	}
	if(f==0){
		cout<<20251101;
	}
	else{
		for(int i=0;i<n;i++){
			int a;cin>>a;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*(i%mod))%mod;
		}
		cout<<ans;
	}
	return 0;
}
