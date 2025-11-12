#include <bits/stdc++.h> 
using namespace std;
const int MOD=998244353;
int main(){
	int n,m;cin>>n>>m;
	string x;cin>>x;
	for(int i=1;i<=n;i++){
		int d;cin>>d;
	}int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%MOD;
	}cout<<ans;
}
