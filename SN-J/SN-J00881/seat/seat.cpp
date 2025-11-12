//SN-J00881，纪柯元，西安市曲江第一中学// 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[100]={};
	int b[100][100]={};
	int c[100][100]={};
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		
	}
	int q=a[1];
	int l=m*n;
	int h=1;
	int p=1;int k=0;
	sort(a+1,a+l+1);
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++){
			b[i][j]=a[l-k];
			k++;
		}
	}
	
		for(int i=2*h;i<=n;i++){
			
			for(int j=1;j<=m;j++){
				c[i][j]=b[i][m+1-j];
				
				
		}h++;
		}
		int w=1;
		for(int i=2*w-1;i<=n;i++){
			
			for(int j=1;j<=m;j++){
				c[i][j]=b[i][j];
				
	}w++;
		}
		
		for(int i=1;i<=n;i++){
		
			for(int j=1;j<=m;j++){
				if(c[i][j]==q){
					cout<<i<<" "<<j;
				}
			
			
		}
}

	return 0;
}















