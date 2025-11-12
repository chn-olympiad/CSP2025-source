#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[105],b[15][15],h,c=0;
	cin>>m>>n;
	for (int i=0;i<m*n;i++){
		cin>>a[i];
		h=a[0];
	}
	for (int i=0;i<m*n;i++){
		for (int j=0;j<n*m-i-1;j++){
			if (a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	} 
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[c];
				
				if (a[c]==h){
					cout<<i<<" "<<j;
					return 0;
				}
				c++;
			} 
		}else{
			for(int j=m;j>0;j--){
				b[i][j]=a[c];
				
				if (a[c]==h){
					cout<<i<<" "<<j;
					return 0;
				}
				c++;
			} 
		}
		
	} 
	
}
