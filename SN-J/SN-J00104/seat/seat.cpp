#include<bits/stdc++.h>
const int MAXN=15;
int n,m,a[MAXN*MAXN];
inline bool cmp(int x,int y)
{
	return x>y;
}
inline void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int t=a[1],x=1,y=1,now=1,up=1;
	std::sort(a+1,a+n*m+1,cmp);
	while(1)
	{
		if(a[now]==t)
			break;
		x+=up;
		if(x>n)
			x=n,up*=-1,y++;
		if(x<1)
			x=1,up*=-1,y++;
		now++;
	}
	printf("%d %d\n",y,x);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int T=1;
	while(T--) solve();
	return 0;
}
