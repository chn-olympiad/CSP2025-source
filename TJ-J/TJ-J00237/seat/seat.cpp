#include <bits/stdc++.h>
using namespace std;
int v,m,n,x,p[1001],l[1001][1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n*m;j++){
		cin>>p[j];
	}
	x=p[1];
	for(int j=1;j<=n*m;j++){
		for(int k=1;k<=j;k++){
			if(p[j]>p[k]){
				swap(p[j],p[k]);
			}
		}
	}
	v=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			l[i][j]=p[v];
			v++; 
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=i;k++){
				if(l[m][j]<l[m][k]){
					swap(l[m][j],l[m][k]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(l[i][j]==x){
				printf("%d %d",i,j);
			}
		}
	}
	return 0; 
}	 
