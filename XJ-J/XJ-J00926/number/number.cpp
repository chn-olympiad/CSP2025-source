#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
const int z=10^5;
int a[z];
int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			a[i+1]=0;
		}
	}
	sort(a,a+n);
	int di=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			di=i;
			break;
		}
	}
	sort(a-di,a+n);
	for(int i=0;i<n;i++)
		cout<<a[i];
	cout<<endl;
	int max=1;
	for(int i=0;i<n-1;i++){
		int k=i;
		int xmax=1;
		for(int j=i+1;j<n;j++){
			if((a[j]-1)==a[k]){
				xmax++;
				k=j;
				j++;
			}else{
				continue;
			} 
		}
		if(xmax>max)
			max=xmax;
	}
	cout<<max;
	return 0;
} 
 
