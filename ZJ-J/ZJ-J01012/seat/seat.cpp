#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int k=1;
	int a[n*m+1]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	
	
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-1;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	
	int s[n+1][m+1]={0};
	int i=1,c=1,r=1;
	
	while(i<=n*m){
		if(r>n||r==0){
			if(k){
				r=n;
			}else{
				r=1;
			}
			c++;
			k=(k+1)%2;
		}
		s[r][c]=a[i];
		if(k){
			r++;
		}else{
			r--;
		}
		i++;
	}
	

	k=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[j][i]==ans){
				cout<<i<<" "<<j;
				k=1;
				break;
			}
		}
		if(k){
			break;
		}
	}
	return 0;
}
