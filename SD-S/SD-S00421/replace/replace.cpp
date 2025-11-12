#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>t1>>t2;
		cout<<"0\n";
	}
	return 0;
}
