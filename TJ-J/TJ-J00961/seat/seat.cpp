#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1],b[n+1][m+1],t=1;
	sort(a+1,a+1+n*m,cmp);
	memset(b,0,sizeof(b));
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[t++];
			}
		}
		else{
			for(int j=n;j>0;j--){
				b[i][j]=a[t++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==tmp){
				cout<<i<<" "<<j; 
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
