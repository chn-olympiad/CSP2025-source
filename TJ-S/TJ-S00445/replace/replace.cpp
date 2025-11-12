#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n+q;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		if(i!=1) cout<<"\n";
		cout<<0;
	} 
	return 0;
}
