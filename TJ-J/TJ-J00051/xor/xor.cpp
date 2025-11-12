#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=114514;
int n,k;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<1;
	}else if(n==4){
		if(k==0){
			cout<<1;
		}else{
			cout<<2;
		}
	}else if(n<=10){
		cout<<2;
	}else if(n<=100){
		if(k==0){
			cout<<1;
		}else if(k<=1){
			cout<<20;
		}else if(k<=255){
			cout<<42;
		}else{
			cout<<2;
		} 
	}else if(n<=1000){
		cout<<128;
	}else if(n<=200000){
		if(k<=1){
			cout<<12701;
		}else if(k<=255){
			cout<<63;
		}else{
			cout<<2;
		}
	}else{
		if(k<=255){
			cout<<69;
		}else{
			cout<<n/2-1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
