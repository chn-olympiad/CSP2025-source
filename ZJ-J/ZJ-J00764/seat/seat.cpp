#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109],ans;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(ans==a[i])
		{
			printf("%d ",i/n+1);
			if(i/n%2==0) printf("%d",i%n);
			else printf("%d",n-(i%n));
			break;
		}
	return 0;
}
