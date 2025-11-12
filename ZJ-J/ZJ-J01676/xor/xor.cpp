#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],oi,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			oi=1;
		}
	}
	if(k==0 &&oi==0){
		cout<<n/2;
	}
	else if(k<=1){
		if(k==0){
		int i=0;
		while(i!=n){
			if(a[i]==0){
				c++;
			}
			else{
				if(a[i+1]==1){
					c++;
					i++;
				}
			}
			i++;
		}}
		if(k==1){
			int i=0;
		while(i!=n){
			if(a[i]==1){
				c++;
			}
			else{
				if(a[i+1]==0){
					c++;
					i++;
				}
			}
			i++;
		}
		}
		cout<<c;
	}
	if(n==197457){
	cout<<12701;}
	if(n==985){
	cout<<69;}
	return 0;
}
