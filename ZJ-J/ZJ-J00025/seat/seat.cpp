#include<bits/stdc++.h>
using namespace std;
int s,n,m,a[110],ans,len,u,v;
bool cmp(int xx,int yy)
{
	return xx>yy;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n*m; i++)    scanf("%d",&a[i]);
	ans = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++)
	{
		if(a[i]==ans)
		{
			len = i;
			break;
		}
	}
	u = ceil(len*1.0/n);
	s = n*(u-1);
	if(u%2)   v = len-s;
	else    v = n-(len-s)+1;
	printf("%d %d",u,v);
	return 0;
}
