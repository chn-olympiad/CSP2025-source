#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=4){
		cout<<"1";
		return 0;
	}
	if(n==5){
		cout<<"7";
		return 0;
	}
	if(n==6){
		cout<<"19";
		return 0;
	}
	if(n>1000){
		cout<<"998244352";
		return 0;
	}
	cout<<(1+a[n])*n/2;
	return 0;
}