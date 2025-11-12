#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w");
	freopen("seat.out","r");
	int n,m;
	cin>>n>>m;
	int z=n*m;
	int a[z];
	int x=0;
	int k;
	cin>>k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	int c[m][n];
	int b[n*m];
	for(int j=1;j<=n*m;j++){
		int maxn=a[1];
		for(int i=n*m;i>0;i--){
			if(maxn<a[i]){
				maxn=a[i];
			}
			cout<<maxn<<" ";
		}
		b[j]==maxn;	
	}
	for(int i=1;i<=m*n;i++){
		cout<<b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		//nÐÐmÁÐ
			if(i%2!=0){
				c[i][j]=a[x];
				if(c[i][j]==k){
					cout<<i<<j;
					break;
				}
				x++;
			}else{
				c[j][n-j]=a[x];
				x++;
				if(c[i][j]==k){
					cout<<i<<j;
					break;
				}
			}	 
		}
	}
	return 0;
}
