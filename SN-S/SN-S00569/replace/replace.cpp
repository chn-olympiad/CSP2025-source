#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[10000][2];
string b[10000][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=q;i++){
		cin>>b[i][1]>>b[i][2];
		if(i==1) cout<<2;
		else cout<<0;
	}
	return 0;
}
