#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[50006];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	string a;
	cin>>a;
	int w=0;
	for(int i=1; i<=n; i++) {
		if(a[i-1]=='1') w++;
		cin>>b[i];
		if(b[i]!=0) l++;
	}
	if(w<m) {
		cout<<0;
		return 0;
	}
	if(l<m) cout<<0;
	else {
		int p=1;
		while(n) {
			p*=n;
			p%=998244353;
			n--;
		}
		cout<<p;
	}
	return 0;
}
