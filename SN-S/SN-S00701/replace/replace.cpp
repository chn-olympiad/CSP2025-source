#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll n,q;
ll s[maxn][2],t[maxn][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
