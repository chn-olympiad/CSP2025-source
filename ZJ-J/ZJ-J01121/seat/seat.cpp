#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,s,R,b[20][20],a[110];
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	x=1;y=1;s=1;
	while(x<=n&&y<=m&&x>=1&&y>=1){
		b[x][y]=a[s];
		if(y%2==1){
			x++;
			if(x>n) x=n,y++;
		}
		else{
			x--;
			if(x<1) x=1,y++;
		}
		s++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==R){
				cout<<j<<" "<<i;
				return 0;
			}
	return 0;
}