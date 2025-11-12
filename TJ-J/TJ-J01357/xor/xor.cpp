#include<bits/stdc++.h>
using namespace std;
int a,k,n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k>>n>>m;
	if(n^m==0) cout<<1;
	else cout<<0;
	return 0;
} 
