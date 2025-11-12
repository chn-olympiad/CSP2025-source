#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=500+9;
int n,m,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		ans=(ans%mod*i%mod)%mod;
	}
	cout<<ans;
	return 0;
}
