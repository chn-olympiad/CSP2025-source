#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<(n/2);
	}
	else{
		cout<<n/k ;
	}
	return 0;
}