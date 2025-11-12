#include<bits/stdc++.h>
using namespace std;
int a[105],dp[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,xx,yy;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		dp[x][y]=a[i];
		if(a[i]==k){
			xx=x;
			yy=y;
		}
		if(y&1){
			if(x==n) y++;
			else x++;
		}
		else{
			if(x==1) y++;
			else x--;
		}
	}
	cout<<yy<<" "<<xx;
	return 0;
}
