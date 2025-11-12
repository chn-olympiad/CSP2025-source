#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],dt[105][105],x=1,y=1,cnt=0,ans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(;y<=m;y++){
		for(;x<=n;x++){
			dt[x][y]=a[++cnt];
		}
		x=n;
		y++;
		if(y>m)break;
		for(;x>=1;x--){
			dt[x][y]=a[++cnt];
		}
		x=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dt[i][j]==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
