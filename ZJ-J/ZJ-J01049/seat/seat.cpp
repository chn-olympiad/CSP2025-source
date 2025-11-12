#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],v,d,x,y;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	v=a[1];
	for(int i=2;i<=n*m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==v)
			d=i;
	x=ceil(1.0*d/n);
	if(x%2==1)
		y=d-(x-1)*n;
	if(x%2==0)
		y=n-(d-(x-1)*n)+1;
	printf("%d %d",x,y);
	return 0;
}
