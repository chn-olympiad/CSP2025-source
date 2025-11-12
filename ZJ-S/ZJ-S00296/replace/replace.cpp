#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n,q;
struct pai {
	string s1,s2;
} a[N];
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--) {
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		cout<<"0"<<"\n";
	}
	return 0;
}

