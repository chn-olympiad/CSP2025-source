#include<bits/stdc++.h>
using namespace std;
int a,s,d[10004],w=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>s;
	for(int z=1; z<=a*s; z++){
		cin>>d[z];
	}
	int p=d[1];
	for(int z=2; z<=a*s; z++){
		if(d[z]>p){
			w++;
		}
	}
	int xx=1,yy=1;
	for(int z=1; z<w; z++){
		if(yy%2==1)xx++;
		else xx--;
		if(xx>a){
			yy++;
			xx--;
		} 
		if(xx<=0){
			yy++;
			xx++;
		}
	}
	cout<<yy<<" "<<xx;
	return 0;
} 
/*
3 3
94 95 96 97 98 99 100 93 92
*/
