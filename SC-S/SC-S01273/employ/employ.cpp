#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],ans,cnt;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cnt=(n-m+2)*(n-m+1)/2%mod;
	for(int i=1;i<=m;i++){
		ans=ans*i%mod;
	}
	ans=ans*cnt%mod;
	cout<<ans;
	return 0;
}
