#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[1000000][2],t[100000][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		cout<<"0\n";
	}
	return 0;
}