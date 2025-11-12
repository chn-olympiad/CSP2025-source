#include <bits/stdc++.h> 
using namespace std;
int a[105],b[12][12];
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[0];
	sort(a,a+n*m);
	int ans=m-abs(m-n);

	for(int i=n*m-1;i>=0;i--){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;j++){
				if(m%2==1){
					if(m==1){
						b[n][m]=a[m*n];	
						b[n][m+1]=a[m*n+1];										
					}
					else{
						b[n][m]=a[m*n-(ans-n)];
						b[n][m+1]=a[m*n-(ans-n)+1];
					}
				}
				else{
					b[n][m]=b[n-1][m]+b[n-1][m-1]-b[n][m-1];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				printf("%d %d",i,j);
			}
		}
	}	
	return 0;
} 
