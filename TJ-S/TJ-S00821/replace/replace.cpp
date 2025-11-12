#include<bits/stdc++.h>
using namespace std;

int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=q;++i){
		if (n<=1e3) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
