#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL read()
{
	char c=getchar();
	LL f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(LL x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const LL N=1e5+5;
LL t,n,a[N][4],b[4][N],cnt[4];
int main()
{
//	freopen("club5.in","r",stdin);
//	freopen("cdo.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=3;i++) cnt[i]=0;
		LL ans=0;
		for(int i=1;i<=n;i++)
		{
			LL pos=0;
			for(int j=1;j<=3;j++)
			{
				a[i][j]=read();
				if(a[i][j]>=a[i][pos]) pos=j;
			}
			cnt[pos]++;
			b[pos][cnt[pos]]=-1e18;
			ans+=a[i][pos];
			for(int j=1;j<=3;j++)
			{
				if(j!=pos) b[pos][cnt[pos]]=max(b[pos][cnt[pos]],a[i][j]-a[i][pos]);
			}
		}
		LL mx=max(cnt[1],max(cnt[2],cnt[3]));
		if(mx>n/2)
		{
			if(mx==cnt[1])
			{
				sort(b[1]+1,b[1]+1+cnt[1],greater<LL>());
				for(int i=1;i<=mx-n/2;i++) ans+=b[1][i];
			}
			else if(mx==cnt[2])
			{
				sort(b[2]+1,b[2]+1+cnt[2],greater<LL>());
				for(int i=1;i<=mx-n/2;i++) ans+=b[2][i];
			}
			else
			{
				sort(b[3]+1,b[3]+1+cnt[3],greater<LL>());
				for(int i=1;i<=mx-n/2;i++) ans+=b[3][i];
			}
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}
/*

*/