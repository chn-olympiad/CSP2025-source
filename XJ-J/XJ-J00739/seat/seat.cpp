#include <bits/stdc++.h>
using namespace std;
int a[11][11],b[101],c,n,m,t,l=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//
	cin>>n>>m;
	for(int i=1;i<m*n;i++){
		cin>>b[i];
		if(i==1){
			c=b[i];
		}	
	}
	for(int i=m*n;i>0;i--){
		for(int j=1;j<=i;j++){
			if(b[j]<b[j+1]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	for(int i=1;i<=m/2;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[l];
			l++;
		}
		i++;
		for(int j=n;j>=1;j--){
			a[i][j]=b[l];
			l++;
		}
	}
	if(m%2==1){
		for(int j=1;j<=n;j++){
			a[m][j]=b[l];
			l++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==c){
				cout<<i<<' '<<j;

			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
