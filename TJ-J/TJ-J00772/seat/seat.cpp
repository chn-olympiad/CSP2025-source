#include<bits/stdc++.h>

using namespace std;
int n,m,g,h,gh,a[105],b[15][15],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	h=n*m;
	for(int i=1;i<=h;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+h+1,cmp);
	for(int i=1;i<=h;i++){
		if(a[i]==g){
			gh=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0) {
			b[1][i]=k+2*n;
			k=k+2*n;
		}else{
			b[1][i]=b[1][i-1]+1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==0){
				b[i][j]=b[i-1][j]-1;
			}else{
				b[i][j]=b[i-1][j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==gh){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
