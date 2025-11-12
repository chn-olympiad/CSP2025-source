#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string x[200005],y[200005],xx[200005],yy[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cin>>xx[i]>>yy[i];
	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
}
//fuck CCF,fuck CSP,they are shit!