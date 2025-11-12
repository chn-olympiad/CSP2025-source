#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int p[m+1][n+1];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int v=0;
	int s[n*m];
	for(int i=0;i<n*m;i++){
		s[i]=a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>0;j--){
				p[i][j]=a[v];
				v++;
			} 
		}else{
			for(int u=1;u<=n;u++){
				p[i][u]=a[v];
				v++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(p[i][j]==s[0]){
				cout<<i<<" "<<j;
			}
		}
	}
	
	
	
	
	return 0;
} 
