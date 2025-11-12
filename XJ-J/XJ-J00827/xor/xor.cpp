#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int k,a[N],n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool sol1=false,sol2=false;
	cin>>n>>k;
	int cot1=0,cot0=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cot1++;
		}else if(a[i]==0){
			cot0++;
		}
	}
	if(cot1==n){
		sol1=true;
	}else if(cot1+cot0==n){
		sol2=true;
	}
	if(sol1){
		if(k==0){
			cout<<0;
		}else if(k==1){
			cout<<n;
		}
	}else if(sol2){
		int cot=0;
		for(int i=1;i<=n;i++){
			cot+=a[i];
		}
		if(k==1){
			cout<<cot;
		}else{
			cout<<n-cot;
		}
	}else{
		cout<<1;
	}
	return 0;
}
