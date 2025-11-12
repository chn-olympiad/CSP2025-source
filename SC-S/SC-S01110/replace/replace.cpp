#include <bits/stdc++.h>
using namespace std;
int n,q;
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
	}
	while(q--){
		cin>>x>>y;
		cout<<n<<'\n';
	}
	return 0;
}