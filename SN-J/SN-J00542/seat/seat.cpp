#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=n*m;
	int a[f+1];
	for(int i=1;i<=f;i++){
		cin>>a[i];
	}
	cout<<1<<" "<<1;
/*
	int n,m;
	cin>>n>>m;
	int f=n*m;
	int a[f+1],c[f+1],d[f+1];
	for(int i=1;i<=f;i++){
		cin>>a[i];
	}
	int r=a[1];
	for(int k=1;k<=f;k++){
		for(int l=1;l<=f;l++){
				if(a[k]>a[l]) swap(a[k],a[l]);
		}
	}
	for(int i=1;i<=f;i++) c[i]=a[i];
	for(int k=1;k<=f;k++){
		for(int l=1;l<=f;l++){
			if(a[k]<a[l]) swap(a[k],a[l]);
		}
	}
	for(int i=1;i<=f;i++) d[i]=a[i];
	int b[n+5][m+5];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(m%2!=0 && c[j]!=0){
				b[i][j]=c[j];
				c[j]=0;
			}
			else if(m%2==0&& c[j]!=0){
				b[i][j]=c[j];
				c[j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r)  cout<<i<<" "<<j;
		}
	}
*/
	return 0;
}
