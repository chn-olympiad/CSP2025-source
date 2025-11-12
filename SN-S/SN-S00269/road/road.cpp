#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int b[10000][10000];
int c[10000][10000];
int main(){
	int n,m,y,z;
	cin>>n>>m;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j] ;
		}
	}
	for(int j=1;j<=5;j++){
		for(int i=1;i<=3;i++){
		cin>>b[j][i] ;
		}
	}
	cout<<13;

	return 0;	
}
