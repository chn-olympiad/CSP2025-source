#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a1[n]={0}; 
	cin>>n>>m>>k;
	int a[n][n]={0},x[m],y[m],z[m];
	for(int i=0;i<m;i++){
		cin>>x[i]>>y[i]>>z[i];
		a[x[i]][y[i]]=z[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]>a1[i]){
				a1[i]=a[j][i];
			}
			if(a[j][i]!=0){
				if(a[j][i]<a1[i]){
					a1[i]=a[j][i];
					const a1[j]=
				}
			}
		}
	}
	
	return 0;
}
