#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int pp,int qq)
{
	return pp>qq;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int num=a[1],pos=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==num)
		{
			pos=i;
			break;
		}
	int c=(pos+n-1)/n,r=0;
	if(c%2==1)	r=pos-(c-1)*n;
	else		r=c*n-pos+1;
	printf("%d %d",c,r);
	return 0;
}
