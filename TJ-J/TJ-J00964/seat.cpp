#include <iostream>
#include <cstdio> 
#include <cmath>
using namespace std;
int main(){
	fropen("seat.in","r",ctdin);
	fropen("seat.out","w",ctdout);
	int m,n;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a[n*m]);
	for(int i=0;i<n;i++){
		for(int j=0;i<m;j++){
			
		}
	} 
	return 0;
} 
