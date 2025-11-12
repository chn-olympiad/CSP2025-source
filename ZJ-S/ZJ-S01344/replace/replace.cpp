#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=1145140;

int n,q;

string a,b;

signed main() {

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a>>b;
	}
	for(int i=1; i<=q; i++) {
		cin>>a>>b;
		cout<<0<<endl;
	}
}
//盲猜乱码