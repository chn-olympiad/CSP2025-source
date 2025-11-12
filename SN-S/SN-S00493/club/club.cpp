//SN-S00493 PR++ 47 GXYZ
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,T,a[N][3],b[N],cnt[3],val[N],t[N];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<3;i++) cnt[i]=0;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=0,val[i]=-1e9;
			for(int j=0;j<3;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][b[i]]) b[i]=j;
			}
			cnt[b[i]]++;
			for(int j=0;j<3;j++)
			{
				if(j!=b[i]) val[i]=max(val[i],a[i][j]-a[i][b[i]]);
			}
			sum+=a[i][b[i]];
		}
		int fl=5;
		for(int i=0;i<3;i++)
		{
			if(cnt[i]>(n/2)) fl=i;
		}
		if(fl==5)
		{
			printf("%d\n",sum);
			continue;
		}
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==fl) t[++tot]=val[i];
		}
		sort(t+1,t+tot+1);
		for(int i=(n/2)+1;i<=tot;i++) sum+=t[i];
		printf("%d\n",sum);
	}
	return 0;
}
