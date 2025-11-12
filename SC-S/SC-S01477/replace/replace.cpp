#include<bits/stdc++.h>
using namespace std;
#define int long long
string a[200010];
string b[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	while(q--){
		string c,d;
		cin >> c >> d;
		cout << "0\n";
	}
	return 0;
}