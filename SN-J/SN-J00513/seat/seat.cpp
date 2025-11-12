#include<bits/stdc++.h>
using namespace std;
int a[10005];
int s[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+m*n+1,cmp);
	int h=1;
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		s[x][y]=a[i];
		if(x==n||x==1&&i!=1){
			y++;
			i++;
			s[x][y]=a[i];
			h*=-1;
		}
		x+=h;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==ans){
				cout<<j<<' '<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
