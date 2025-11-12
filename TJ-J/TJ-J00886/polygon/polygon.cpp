#include <bits/stdc++.h>
using namespace std;
int main(){	
	int n,b=0;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(a[1]+a[2]+a[3]>2*a[3]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}


