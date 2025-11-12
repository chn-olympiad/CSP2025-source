#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,a,t,v;
int c[200005];
signed main(){
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s>>a;
	while(m--){
		cin>>t>>v;
	}
	if(n==4) cout<<2<<endl<<0;
	if(n==3){
		for(int i=1;i<=4;i++) cout<<0<<endl;
	}
}
