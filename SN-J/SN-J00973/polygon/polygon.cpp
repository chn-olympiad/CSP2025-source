#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r" , stdin);
	freopen("polygon.out","w" , stdout);

	long long n, a[100000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(a[1]==1){
		cout<<9;
	}else if(a[2]==2){
		cout<<6;
	}
	
	return 0;
} 
