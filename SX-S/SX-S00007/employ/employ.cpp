#include<bits/stdc++.h>
#define int long long
#define FREOPEN(x) freopen(x ".in","r",stdin),freopen(x ".out","w",stdout);
using namespace std;
signed main() {
	FREOPEN("employ")
	int n,m,flag1=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) {
		int t;
		cin>>t;
		if(!t) {
			flag1=0;
		}
	} if(m==n&&!flag1) {
		cout<<0;
		return 0;
	}
	return 0;
}
