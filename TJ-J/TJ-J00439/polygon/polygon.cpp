#include<bits/stdc++.h>
using namespace std;
polygon.in;
polygon.out;
int main(){
	int n=0,add=0,sum=0;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j-1]+a[j-2]<=a[j]){
				j++;
				
			}
		}
		add++;
	}
	cout<<add;
return 0;
}

