#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b=0,n[10][10],m;
	cin>>a;
	for(int k=a;k>0;k--){
		cin>>m;
		int c[m];
		for(int i=0;i<m;i++){
			for(int j=1;j<=3;j++){
				cin>>n[i][j];
				c[i]=max(n[i][1],max(n[i][2],n[i][3]));
			}
		}
		for(int k=0;k<m;k++){
			b=c[k]+b;
		}
		cout<<b;
		b=0;
	}
	return 0;
}
