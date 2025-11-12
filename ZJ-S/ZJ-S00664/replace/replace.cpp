#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int d,mod=97;
	for(int i=1;i<=q;i++){
		cout<<min(0,(n-q)*d%mod)<<endl;
	}
	return 0;
}
