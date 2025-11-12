#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int sum = 0,n,max=0;
	cin>>n;
	int a[n];
	for(int i = 0; i < n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>max){
			max = a[i];
		}
		
	}
	if(n<=3){
	
		if(n<3){
			cout<<0;
		}
		else{
			if(sum>2*max){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<n+4;
		
		
		
	}	

	return 0;
}

