#include<bits/stdc++.h>
 using namespace std;
 const int N=105;
 int main(){
 	int n,m;
 	cin>>n>>m;
 	int a[N][N],a1[N]; 
	for(int i=0;i<n*m;i++){
			cin>>a1[i];
		}
	for(int i=0;i<n*m;i++){
			a1[i]=sort(a1[i+1],a1[i]);
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m*n;k++)
			a[i][j]=a1[k];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j];
		}
	}
 	return 0;
 }
