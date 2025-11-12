#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],k=1,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1])
			k++;
	x=(k-1)/n+1;
	if(x%2==1)
		y=(k-1)%n+1;
	else
		y=n-(k-1)%n;
	printf("%d %d\n",x,y);
	return 0;
}
