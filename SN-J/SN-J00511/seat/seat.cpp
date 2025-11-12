#include<bits/stdc++.h>
using namespace std;
int n,m,sum,c,r;
int seat[15][15];
int a[105];
bool cmp(int x,int y){
	if(x<y) return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i,j=1;i<=m;i++){
		if(i%2==1){
			for(int k=1;k<=n;k++){
				seat[k][i]=a[j];
				j++;
			}
		}
		else{
			for(int k=n;k>=1;k--){
				seat[k][i]=a[j];
				j++;
			}	
		}
	}
	for(int r=1;r<=n;r++){
		for(int c=1;c<=m;c++){
			if(seat[r][c]==sum){
				cout<<c<<' '<<r;
			}
		}
	}
	return 0;
}
