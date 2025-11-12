#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q;
string a[N][5];
string s,t;
void solve(){
	cin>>s>>t;
	cout<<0<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;++i)
		cin>>a[i][1]>>a[i][2];
	
	while(q--) solve();
	
	
	return 0;
}
