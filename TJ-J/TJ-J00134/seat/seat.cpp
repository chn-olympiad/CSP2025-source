#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m][n];
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	
	cout<<n<<" "<<m;
	
	return 0;
}
