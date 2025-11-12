#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int a=0;a<n;a++){
		cin>>arr[a];
	}
	int cnt=0; 
	for(int a=0;a<n-3;a++){
		for(int b=a;b<n-3;b++){
			for(int c=b;c<n-3;c++){
				if(arr[a]+arr[b]+arr[c]>=2*max(arr[a],max(arr[b],arr[c]))){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 
