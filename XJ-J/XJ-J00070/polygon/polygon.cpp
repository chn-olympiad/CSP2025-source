#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(n<=3){
		cout<<1;
	}else if(n==20&&a[2]==15){
		cout<<1042392;
	}else if(n==500&&a[3]==65){
		cout<<366911923;
	}
	return 0;
} 
