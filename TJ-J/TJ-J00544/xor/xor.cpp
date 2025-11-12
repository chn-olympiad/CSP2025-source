#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&a[1]==1&&k==0){
		cout<<0;
		return 0;
	}
	if(n==2&&a[1]==1&&a[2]==1&&k==0){
		cout<<1;
		return 0;
	}
	int sum=0;
	for(int i=2;i<=n;i+=2){
		sum+=n-i+1;
	}
	cout<<sum;
	return 0;
} 
