#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1])sum++;
	}
	sum++;
	if(sum%(2*n)<=n&&sum%(2*n)>0)
	{
		x=(sum-1)/n+1;
		y=sum%n;
		if(y==0)y=n;
	}else{
		x=(sum-1)/n+1;
		y=n-sum%n+1;
		if(sum%n==0)y=1;
	}
	printf("%d %d",x,y);
	return 0;
}
