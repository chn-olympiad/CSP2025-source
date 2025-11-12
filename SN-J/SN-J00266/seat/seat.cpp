#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","n m",stdin);
	freopen("seat.out","j i",stdout);
	int m,n,c[105],l=0,v=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
		if(c[i]>=c[1])l++;
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				v++;
				if(v==l){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				v++;
				if(v==l){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
} 
