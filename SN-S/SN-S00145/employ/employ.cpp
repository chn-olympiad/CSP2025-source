#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1;char a;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;m=m&&(int(a)-48);
	}
	if(m=1){
		for(int i=1;i<=n;i++){
		    ans*=i;ans%=998244353;
		}
		cout<<ans;
	}
	cout<<1;
	return 0;
	}
