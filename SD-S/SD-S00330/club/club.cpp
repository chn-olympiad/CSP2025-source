#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,a[N][5],id[N],vec[N];
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')
	f=-1;
	res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
int getfir(int x,int y,int z)
{
	if(x>=y&&x>=z)
	return 1;
	if(y>=x&&y>=z)
	return 2;
	return 3;
}
void solve()
{
	int i,j,tot[5],lim,ans=0;
	n=read();lim=n/2;
	tot[1]=tot[2]=tot[3]=0;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=3;j++)
		a[i][j]=read();
		tot[id[i]=getfir(a[i][1],a[i][2],a[i][3])]++;
		ans+=a[i][id[i]];
	}
	int op=0;
	if(tot[1]>lim)
	op=1;
	if(tot[2]>lim)
	op=2;
	if(tot[3]>lim)
	op=3;
	if(!op)
	{
		printf("%d\n",ans);
		return;
	}
	int cnt=0;
	for(i=1;i<=n;i++)
	if(op==id[i])
	{
		sort(a[i]+1,a[i]+4);
		vec[++cnt]=a[i][3]-a[i][2];
	}
	sort(vec+1,vec+cnt+1);
	for(i=1;i<=cnt-lim;i++)
	ans-=vec[i];
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
