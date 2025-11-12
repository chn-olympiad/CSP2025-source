#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
	}
	if(n=3){
		cout<<"1";
	}
	else{
		cout<<((1+n)*n)/2;
	}
	
	return 0;
}
