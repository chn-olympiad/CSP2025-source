#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	int n,sum=0,max=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>max){
			max=a[i];
		}
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(sum>2*max){
		cout<<1;	
	}
	else{
		cout<<0;
	}
	return 0;
}
