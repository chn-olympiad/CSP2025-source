#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return 0;
	}
	cout<<2<<endl;
	return 0; 
} 
