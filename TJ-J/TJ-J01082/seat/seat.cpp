#include<bits/stdc++.h>
using namespace std;
int main(){
//	freomon("seat.in",'r');
//	freomon("seat.out",'w');
	int m,n,t,o,jkl=1;
	cin>>n>>m;
	int a[m*n];
	for (int i=0;i<m*n;i++){
		cin>>a[i];
	}
	o=a[0];
	
	for(int i=0;i<n*m;i++){
		for (int j=i+1;j<n*m+1;j++){
			if (a[j]>a[i]){
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	
	for (int i=0;i<m*n;i++){
		if (a[i]==o){
			o=i;
		}
	}
	for (int x=0;x<n*m;){
		for (int i=1;i<=m;i++){
			if (jkl==1){
				for(jkl<=n;jkl++;){
					a[x]=(i,jkl);
					x++;
				}
			}else{
				for(jkl>=0;jkl--;){
					a[x]=(i,jkl);
					x++;
				}
			}
		}
	}
	cout<<a[o];
	return 0;
}
