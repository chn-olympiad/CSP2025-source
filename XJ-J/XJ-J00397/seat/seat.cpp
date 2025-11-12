#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","w",stdout);
	int a,b,j,m,o;
	int u=1;
	int k,l=1;
	int n[11][11]={0};
	int c[11][11]={0};
	cin >> a >> b;
	for(int i=1;i<=a;i++){
		if(i%2==1){
			for(int x=1;x<=b;x++){
				cin >> c[i][x];	
			}
		}else{
				for(int x=b;x>=1;x--){
				cin >> c[i][x];
			}
		}
	}
	m=c[1][1];
	for(int s=0;s<a;s++){
		for(int z=0;z<b;z++){
			for(int i=1;i<=a;i++){
				if(i%2==1){
					for(int x=2;x<=b;x++){
						if(i-1==u){
							if(c[i-1][j]>c[i][x]){
								n[1+s][1+z]=c[i-1][x];
							}	
						}else if(c[i][x-1]>c[i][x]){
							n[1+s][1+z]=c[i][x-1];
						}//else{
						//	n[1+s][1+z]=c[i][x];
						//}
						j=x;
					}
				}else{
					for(int x=b-1;x>=1;x--){
						if(i-1==u){
							if(c[i+1][j]>c[i][x]){
								n[1+s][b-z]=c[i-1][x];
							}	
						}else if(c[i][x+1]>c[i][x]){
							n[1+s][b-z]=c[i][x-1];
						}//else{
						//	n[1+s][b-z]=c[i][x];
						//}
						j=x;
					}
				}
				if(c) 
				u=i;
				o=z;
			}
		}
		if(n[1+s][b-o]==m){
			k=1+s;
			l=b-o;
		}else if(n[1+s][1+o]==m){
			k=1+s;
			l=1+o;
		}
	}
	cout << k << " " << l;
	return 0;
} 
