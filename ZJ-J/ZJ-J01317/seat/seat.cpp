#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int b[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int r;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=0;i<n;i+=2){
		for(int j=1;j<=m;j++){
			b[i][j]=a[i*m+j];
		}
		for(int j=m;j>=1;j--){
			b[i+1][j]=a[(i+2)*m-j+1];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				cout<<i+1<<" "<<j;
				return 0;
			}
		}
	}
}