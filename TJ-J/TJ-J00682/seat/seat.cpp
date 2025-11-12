#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+m+1]={};
	cin>>a[0];
	int ans=a[0],cnt=n*m;
	for(int i=1;i<cnt;i++){
		cin>>a[i];
	}
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			if(a[i]<a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	int t[n+1][m+1]={},d=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i%2==0){
				t[j][i]=a[d];
				d++;
			}
			else{
				t[j][n-i]=a[d];
				d++;
			} 
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(i%2!=0){
				swap(t[j][i],t[j+1][i]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(t[i][j]==ans){
				cout<<j+1<<" "<<i+1<<endl;
				return 0;
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
