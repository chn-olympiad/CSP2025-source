#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,ans;
int arr[5010],kw[5010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int a=1;a<=n;a++)
		cin>>arr[a];
	sort(arr+1,arr+n+1);
	int mxl=arr[n];
	if(n==3){
		if(arr[3]*2<arr[1]+arr[2]+arr[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	int cf=2;
	for(int a=1;a<n;a++)
		cf=(cf*2)%998244353;
	
	if(mxl==1){
		cout<<cf-1-n*(n+1)/2;
		return 0;
	}
		
		

	return 0;
} 
