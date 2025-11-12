#include<bits/stdc++.h>
using namespace std;
int n,k,a,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}if(a==b) cout<<2;
	else if(a==0||b==0) cout<<1;
	else cout<<0;
	return 0;
}
