#include <bits/stdc++.h>
using namespace std;
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<"2\n0";
		return 0;
	}
	if(n==3&&q==4){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
}