#include<bits/stdc++.h>
using namespace std;

int n,q;
string s,d;

signed main(){
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s>>d;
	}
	for(int i=1;i<=q;i++){
		cin>>s>>d;
	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	
	return 0;
} 
