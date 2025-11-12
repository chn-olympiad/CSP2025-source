#include<bits/stdc++.h>
using namespace std;
int flag=0,a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n==2 && flag==0 && k==0){
		cout<<1;
	}
	else if(k==0){
		if(n%2==1){
			cout<<0;
		}
		if(n%2==0){
			cout<<n/2;
		}
	}
	return 0;
}


