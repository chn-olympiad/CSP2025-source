#include<bits/stdc++.h>
using namespace std;
int a[110],seat[15][15];
bool cmp(int p,int q){
	return p>q;
}
int n,m,r; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i+=2){
		int k=1;
		for(int j=i*n-n+1;j<=i*n+1;j++){
			seat[i][k]=a[j];
			k++;
		}
	}
	for(int i=2;i<=m;i+=2){
		int k=n;
		for(int j=i*n-n+1;j<=i*n+1;j++){
			seat[i][k]=a[j];
			k--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<seat[j][i]<<" ";
			if(seat[j][i]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;//#Shang4Shan3Ruo6SHui4
}
