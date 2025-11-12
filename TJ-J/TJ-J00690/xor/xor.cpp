#include<bits/stdc++.h>
using namespace std;
int a[1048586];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=true,f2=true;
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}if(a[i]>1){
			f2=false;
		}
		if(a[i]==1){
			cnt1++;
		}else if(a[i]==0){
			cnt0++; 
		}
	}
	if(f){
		cout<<n/2;
	}else if(f2){
		if(k==1){
			cout<<cnt1;
		}else{
			cout<<cnt0+cnt1/2;
		}
	}
	
return 0;
}
//1  1 1 1 1 1 1 1  1 1 1 1 1 1 1 1  1 1 1 1
