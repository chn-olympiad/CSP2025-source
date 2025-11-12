#include<bits/stdc++.h>
using namespace std;
int a=0,b,c,d,e=0,f,g[1111];
int abc[11][11];
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	c=a*b;
	cin>>d;
	g[0]=d;
	for(int x=1;x<c;x++){
		cin>>g[x];
	}
	for(int y=0;y<c-1;y++){
		for(int z=y+1;z<c;z++){
			if(g[y]<g[z]){
				f=g[y];
				g[y]=g[z];
				g[z]=f;
			}
		}
	}
	for(int x=1;x<=b;x++){
		if(x%2==0){
			for(int y=a;y>=1;y--){
				if(g[e]==d){
					cout<<x<<' '<<y;
				}
				e++;
			}
		}else{
			for(int y=1;y<=a;y++){
				if(g[e]==d){
					cout<<x<<' '<<y;
				}
				e++;
			}
		}
	}
	return 0;
}
