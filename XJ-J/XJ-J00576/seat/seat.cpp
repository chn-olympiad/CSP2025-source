#include<bits/stdc++.h>
using namespace std;
int n,s[15][15]={},m,k;
char t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m+5;
	int a[l]={};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[j]<a[j+1]) {
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			}
		}
	}
	k=a[0];
	for(int i=0;i<n;i++){
		s[i][0]=a[i];
	}
	for(int i=1;i<m;i++){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				s[j-1][i]=a[i+j+1];	
			}
		}
		else{
			for(int j=n;j>=0;j--){
				s[j][i]=a[i+j+1];	
			}
		}
		i++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]==k){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
