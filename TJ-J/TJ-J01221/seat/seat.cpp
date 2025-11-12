#include<bits/stdc++.h>
using namespace std;
ifstream fin("seat.in");
ofstream fout("seat.out");
int main(){
	int n,m,c,r,e;
	fin>>n>>m;
	int a[n+1][m+1]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			fin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>a[0][0]){
				e = a[0][0];
				a[i][j] = a[0][0];
				a[0][0] = e;
				c = a[i][0];
				r = a[0][j];
			}
			else{
				a[0][0] == a[0][0];
			}
		}
	}
	fout<<c<<r;
	return 0;
}
