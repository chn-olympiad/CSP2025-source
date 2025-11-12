#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out.out","w",stdout);
	
	int n,m,q,z,k;
	cin>>n>>m;
	int a[n*m];
	int c[n];
	int r[m];
	for(int i=0;i<m*n;i++){
		cin>>a[i];//a[0]ÎªÐ¡R³É¼¨ 
	}
	for(int i=0;i<=n;i++){
		c[i]=i+1;
	}
	for(int i=0;i<=m;i++){
		r[i]=i+1;
	}
	z=a[0];
	for(int i=0;i<=m*n;i++){
		for(int j=i+1;j<=i;j++){
			if(a[i]<a[j]){
				q=a[i];
				a[i]=a[j];
				a[j]=q;
			}
		}
	}
	for(int i=0;i<=m*n;i++){
		if(a[i]==z){
			k=i;
		}
	} 
	cout<<r[k]<<" "<<c[k];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
