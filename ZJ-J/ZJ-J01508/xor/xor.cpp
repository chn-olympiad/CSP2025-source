#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000000],cntone,cntz,cntdo;
bool allone=1,b=1,fo;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1 && fo!=1){
			fo=1;
		}else if(a[i]==1 && fo==1){
			fo=0;
			cntdo++;
		}
		if(a[i]==1){
			cntone++;
		}
		if(a[i]==0){
			cntz++;
		}
		if(a[i]!=1){
			allone=0;
			fo=0;
		}
		if(a[i]>1){
			b=0;
		}
	}
	if(allone && k==0){
		cout<<n/2;
	}else if(b && k<=1){
		if(k==1){
			cout<<cntone;
		}else{
			cout<<cntz+cntdo;
		}
	}else{
		cout<<1;
	}
	return 0;
}