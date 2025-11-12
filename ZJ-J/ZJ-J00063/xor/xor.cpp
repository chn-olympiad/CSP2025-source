#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,y,ans,s;
int g[105],h[105];
int xr(int gg,int hh)
{
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));
	int gs=0,hs=0,sum=0;
	while(gg)g[++gs]=gg%2,gg/=2;
	while(hh)h[++hs]=hh%2,hh/=2;
	for(int q=1;q<=max(gs,hs);q++)
		if(g[q]!=h[q])sum+=pow(2,q-1);
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	x=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(x<=n)
	{
		y=x;
		s=0;
		bool f=0;
		while(y<=n)
		{
			s=xr(s,a[y]);
			if(s==k)
			{
				f=1;break;
			}
			y++;
		}
		if(f)ans++,x=y+1;
		else if(!f)x++;
	}
	cout<<ans;
	return 0;
}
