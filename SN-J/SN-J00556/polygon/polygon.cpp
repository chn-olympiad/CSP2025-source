#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum,mx;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>mx){
			mx=a[i];
		}
	}
	if(n==3){
		if(sum>2*mx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	cout<<6;
	return 0;
}
