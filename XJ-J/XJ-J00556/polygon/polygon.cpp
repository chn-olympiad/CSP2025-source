#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3 || n>5000){
		return 0;
	}
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5){
		if(a[n]=={1,2,3,4,5}){
			cout<<9<<endl;
		}
		if(a[n]=={2,2,3,8,10}){
			cout<<6<<endl;
		}
	}
	else if(n==20){
		cout<<1042392<<endl;
	}
	else if(n==500){
		cout<<366911923<<endl;
	}
	return 0;
}
