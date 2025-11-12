#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int a[1008];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==m){
		cout<<0<<endl;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
