#include<bits/stdc++.h>
using namespace std;
const int MAXN=12;
int n,m,a[MAXN*MAXN],num,x,y,cnt,b[MAXN][MAXN],ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	num=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	x=y=cnt=1;
	while(cnt<=n*m){
		while(cnt<=n*m&&x<=n){
			b[x][y]=a[cnt];
			cnt++;
			x++;
		}
		if (cnt>n*m) break;
		x--;
		y++;
		if (y>m) break;
		while(cnt<=n*m&&x>=1){
			b[x][y]=a[cnt];
			cnt++;
			x--;
		}
		if (cnt>n*m) break;
		x++;
		y++;
		if (y>m) break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if (b[i][j]==num){
				ans1=j;
				ans2=i;
				break;
			}
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
