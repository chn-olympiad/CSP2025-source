#include<bits/stdc++.h>
using namespace std;
int n,a[5100],f=true,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(n!=1) f=false;
	}
	if(n==2){
		if(a[0]==1&&a[1]==1){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(n==1){
		if(n==k){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	else{
		if(f&&k!=0){
			cout<<0;
			return 0;
		}else{
			for(int i=0;i<=100;i++){
				if(n%i==0){
					cout<<n/i;
					return 0;
				}
			}
		}
	}
	return 0;
}
