#include<bits/stdc++.h>
using namespace std;
const int N=1500;
int a[N*N];
int b[N][N];
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=n;j>=1;j--){
				b[i][j]=a[++cnt];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[j][n+1-i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(b[j][n+1-i]==x){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		
	}
	return 0;
}
/*
3 3
20 90 56 23 87 45 12 65 85

3 7
5 2 3 6 9 8 7 4 1 62 61 45 65 12 54 87 256 16 89 25 36
*/
