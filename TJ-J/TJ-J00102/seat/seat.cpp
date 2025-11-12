#include<bits/stdc++.h>
using namespace std;
int a[30][30],n,m,cnt=1;
int c[900],d[900];
bool cmp(int g,int h){
	return g>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>c[i];
		d[i]=c[i];
	}
	sort(c+1,c+1+(m*n),cmp);
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				a[i][j]=c[cnt++];
			}
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=c[cnt++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==d[1]){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
