#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,k;
struct jz{
	int lj,q;
};
const int N=1e6;
jz arr[N][N];
int brr[N][N];
int c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int a=1;a<=m;a++){
		int x,y;
		cin>>x>>y;
		arr[x][y].lj=1;
		cin>>arr[x][y].q;
	}
	for(int a=1;a<=k;a++){
		cin>>c[a];
		for(int b=1;b<=n;b++)
			cin>>brr[a][b];
	}
			
	return 0;
} 
