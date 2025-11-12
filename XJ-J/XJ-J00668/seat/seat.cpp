#include <bits/stdc++.h>
using namespace std;
int a[120],b[120],c[20][20];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b[0]=a[0];
	sort(a,a+(n*m),cmp);
	int xb=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			c[i][j]=a[xb];
			cout<<c[i][j]<<endl;
			if(c[i][j]==b[0]){
				cout<<i<<" "<<j;
				return 0;
				
			}
			xb++;	
		
			
			
		}
	}
	return 0;
} 
