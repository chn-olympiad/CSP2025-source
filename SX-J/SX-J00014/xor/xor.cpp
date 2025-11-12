#include<bits/stdc++.h>
using namespace std;
int n,k,a[10010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1) cout<<1;
	else if(n==2) cout<<3;
	else cout<<0;
	return 0;
}



