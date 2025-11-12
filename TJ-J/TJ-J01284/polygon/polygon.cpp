#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		int cnt=0;
		for(int j=n-i;j>=3;j--){
			for(int k=i;k<=j+i;k++){
				
			}
		}
	}
} 
