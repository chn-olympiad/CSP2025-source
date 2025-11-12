#include<iostream>
#include<stdio.h>
#include<algorithm>
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
	sort(a,a+n,greater<int>());
	if(n==3){
		if(a[0]+a[1]+a[2]>2*a[0]){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
