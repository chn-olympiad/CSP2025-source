#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	int s[100];
	int a[m][n];
	int sum=1;
	for(int i=0;i<=n*m;i++){
		cin>>s[i];
	for(int i=1;i<=n*m;i++){
		if(s[i+1]>s[i]){
	        swap(s[i+1],s[i]);
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(s[i]>s[i-1] && sum<n){
				a[i][j]=a[i-1][j];
				cout<<i<<" "<<j<<endl;
			}
			if(sum>=n){
				a[i][j]=a[i][j+1];
			}
		}
	}
	else if(n==2){
		cout<<1<<" "<<2<<endl;
	}
	else{
		cout<<2<<" "<<2<<endl;
	}
	return 0;
}
