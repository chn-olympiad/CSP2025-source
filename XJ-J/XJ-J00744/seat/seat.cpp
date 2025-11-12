#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int f[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;//hang
	int m;//lie
	cin>>n>>m;
	int af;
	for(int i=1;i<=n*m;i++) {
		cin>>f[i];af=f[1];
		
	}
	
	sort(f+1,f+1+(n*m),cmp);
	
	int k=1;
	for(int i=1;i<=m;i++) {
		if(i%2==1){
			for(int j=1;j<=n;j++) {
				
				a[i][j]=f[k++];
					
			}
				
		}else{
			for(int j=n;j>=1;j--) {
				
				
				a[i][j]=f[k++];
				
				
				
				
			}
			
		}
		
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			
			if(a[i][j]==af){
				cout<<i<<" "<<j; return 0; 
			}
		}
		
	}
	return 0;
	
} 
/*
#Shang4Shan3Ruo6Shui4
2 2
98 99 100 97
*/ 
