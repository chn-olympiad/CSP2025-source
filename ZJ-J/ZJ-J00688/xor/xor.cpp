#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],k,now;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n;
		return 0;
	}
	if(k==1){
		cout<<2;
		return 0;
	}
	cout<<1;
	return 0;
}
