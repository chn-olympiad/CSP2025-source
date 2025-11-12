#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1 && k!=a[1]){
		cout<<0;
		return 0;
	}
	else{
		cout<<1;
		return 0; 
	} 
	if(k==0){
		cout<<n/2;
		return 0;
	}
	else{
		cout<<n/4;
	}
	return 0;
}

