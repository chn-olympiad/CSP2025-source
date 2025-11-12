#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m,ans=1;
int c[505];
string s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=m;i--){
		ans=((ans%MOD)*(i%MOD))%MOD;
	}
	cout<<ans;
	return 0;
}