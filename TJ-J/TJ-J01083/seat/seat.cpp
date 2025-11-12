#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m;
int c[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int p=c[1],num=1;
	sort(c+1,c+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=c[num];
				num++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j]=c[num];
				num++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==p){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
