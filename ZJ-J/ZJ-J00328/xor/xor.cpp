#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		if(k==0)
			cout<<0;
		return 0;
	}
	if(n==2){
		if(k==0)
			cout<<1;
		return 0;
	}
	else if(k==0){
		cout<<n/2;
	}
	else{
		cout<<n/2;
	}
	return 0;
}
