#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in",'w',stdin);
//	freopen("club.out",'r',stdout);
	int n,m,k,minlu=210000000,mink=210000000;
	cin>>n>>m>>k;
	int u[n];
	int v[n];
	int w[m];
	int c[k];
	int a[k][n+1];
	a[k][n+1]={0};
	for (int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for (int j=0;j<k;j++){
		cin>>c[j];
		for (int ji=0;ji<n;ji++){
			cin>>a[j][ji];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=i-1;j<n-1;j++){
			if ((w[i]+w[j]<minlu)&&(u[i]!=u[j])&&(v[i]!=v[j])){
				minlu=w[i]+w[j];
			}
		}
	}
	
	for (int i=0;i<n;i++){
		for (int x=0;x<=n;x++){
			a[i][n+1]+=a[i][x];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=i-1;j<n-1;j++){
			if (((c[i]+a[i][n+1])<(c[j]+a[j][n+1]))&&((c[i]+a[i][n+1])<mink)){
				mink=c[i]+a[i][n+1];
			}
		}
	}
	cout<<minlu+mink-10;
	return 0;
}
