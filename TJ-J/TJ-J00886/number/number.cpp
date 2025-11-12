#include <bits/stdc++.h>
using namespace std;
int main(){	
	int a[9];
	int s;
	for(int i=1;i<=1000000;i++){
		cin>>s;
		if(s==1 or s==2 or s==3 or s==4 or s==5 or s==6 or s==7 or s==8 or s==9){
			a[s]++;
		}
	}
	for(int i=9;i>=1;i--){
		int b;
		b=a[i];
		for(int j=b;j>=1;j--){
			cout<<i;
		}
	}
	return 0;
}


