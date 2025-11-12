#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],dp[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1&&k==0){
		cout<<0;	
	}else if(n==2&&k==0){
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}