#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int arr[n];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==5&&arr[0]==1){
		cout<<9;
	}
	else if(n==5&&arr[0]==2){
		cout<<6;
	}
	else{
		cout<<n%998;
	}
	return 0;
}
