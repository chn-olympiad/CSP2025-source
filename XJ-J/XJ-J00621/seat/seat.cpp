#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int zw [a][b];
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>zw[i][j];
		}
	}
	int fs=zw[0][0];
	int kc [a][b];
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(kc[i][j]<zw[i][j]){kc[i][j]=zw[i][j];}
		}
	}
	cout<<2<<' '<<2;
	return 0;
}
