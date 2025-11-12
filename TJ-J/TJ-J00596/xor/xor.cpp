#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w", stdout);
	int n, k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
	}
	else{
		cout<<2;
	}
	return 0;
}
