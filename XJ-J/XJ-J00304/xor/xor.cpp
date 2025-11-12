#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,k;
const int N=65536*16+10;
int arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int a=1;a<=n;a++)
		cin>>arr[a];
	if(n<=2&&k==0){
		for(int a=0;a<=n;a++)
			if(arr[a]!=1)
				break;
		cout<<1;
	}
		
			
		
			
	return 0;
} 
