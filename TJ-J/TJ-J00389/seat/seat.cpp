#include<bits/stdc++.h>
using namespace std;
const int mx = 20;

/*
3 3
94 95 96 97 98 99 100 93 92
4 2
80 86 93 82 81 79 77 76
*/

int n,m,r,mn=200,ansi,ansj;
int sc[mx][mx],t[mx*mx];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >>sc[i][j];
			t[sc[i][j]] ++;
			if(sc[i][j]<mn) mn = sc[i][j];
		}
	}
	r = sc[0][0];
	int i=0,j=1,x=1;
	for(int s=100;s>=mn;s--){
		if(t[s]!=0){
			i+=x;
			if(i>n){
				j++;
				i--;
				x = -1;
			}
			if(i==0){
				j++;
				i++;
				x = 1;
			}
			if(s==r){
				ansi = i;
				ansj = j;
			}
		}
	}
	
	cout <<ansj<<' '<<ansi;
	
	
	return 0;
}
