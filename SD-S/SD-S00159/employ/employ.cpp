#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
		cin>>s;
		long long cnt=1;
	for(int i=1;i<=n;i++){
		cnt=(cnt%mod*i%mod)%mod; 
	}
	cout<<cnt;
}
