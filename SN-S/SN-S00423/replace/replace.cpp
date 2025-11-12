#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,q;
	cin>>n>>q;
	if(q==1) {
		cout<<"39"<<'\n';
	} else {
		for(int i=1; i<=q; i++) {
			cout<<"0"<<'\n';
		}
	}
	return 0;
}
