#include<iostream>
#include<stdio.h>
using namespace std;
struct road{
	int a,b,n;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	road r[m];
	for(int i=0;i<m;i++){
		cin>>r[i].a>>r[i].b>>r[i].n;
	}
	int c[k];
	int a[k][n];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}