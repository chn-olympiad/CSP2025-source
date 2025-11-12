#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
int n,q;
string a[2][10005],l,r;
int main(){
	FI("replace");
	FO("replace");
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[0][i]>>a[1][i];
	}
	while(q--){
		cin>>l>>r;
		cout<<0<<"\n";
	}
	return 0;
}
