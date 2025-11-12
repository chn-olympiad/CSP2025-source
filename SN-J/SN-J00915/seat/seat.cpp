//MZKXGDFZ
#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[105];
int cnt=1; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])cnt++;
	}
	if(cnt<=n)printf("1 %d",cnt);
	else{
		x=cnt/n;
		y=cnt%n;
		if(x%2==1)printf("%d %d",x+1,n-y+1);
		else printf("%d %d",x+1,y);
	}
	return 0;
}
