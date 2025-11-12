#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,r;
	cin>>n>>m;
	int a[n][m]={{0}};
	int b[n*m],c[101]={0};
	cin>>r;
	b[0]=r;
	for (int i=1;i<n*m;i++){
		cin>>b[i];
	}
	for (int i=1;i<n*m-1;i++){
		c[b[i]]++;
	}
	int k=0;
	for (int i=1;i<=100;i++){
		for (int j=0;j<c[i];j++){
			b[k]=i;
			k++;
		}
	}
	for (int i=0 ;i<n*m;i++){
		if (b[i]==r){
			cout<<i;
		}
	}
	return 0;
}
