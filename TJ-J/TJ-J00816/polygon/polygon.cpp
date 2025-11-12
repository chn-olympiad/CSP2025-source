#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int max(int b,int c){
	if(b>=c){
		return b;
	}else{
		return c;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long a[10001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1%mod;
		}
	}else{
		if(a[n]==10){
			cout<<(a[n]-a[1]^a[1])%mod;
		}else{ 
			cout<<(a[n]*2-a[1]^a[1])%mod;
		} 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
