#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m,s,l,a[N][3],ans;
inline int read()
{
	char x=getchar();
	int ans=0;
	while(x<'0'||x>'9')
		x=getchar();
	while(x>='0'&&x<='9')
	{
		ans=(ans<<1)+(ans<<3)+(x^48);
		x=getchar();
	}
	return ans;
}
struct qwq
{
	int val1,val2;
}b[N];
bool cmp(qwq a,qwq b)
{
	return a.val1-a.val2>b.val1-b.val2;
}
void solve(int op)
{
	for(int i=1;i<=n;i++)
	{
		int val1=0,val2=0;
		for(int j=0;j<=2;j++)
		{
			if(j==op)
				val1=a[i][j];
			else
				val2=max(val2,a[i][j]);
		}
		b[i].val1=val1;
		b[i].val2=val2;
	}
	int sigma=0;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n/2;i++)
		sigma+=b[i].val1;
	for(int i=n/2+1;i<=n;i++)
		sigma+=b[i].val2;
	ans=max(ans,sigma);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//puts("QWQ");
	for(int T=read();T;T--)
	{
//		cout<<T<<endl;
		n=read();
		for(int i=1;i<=n;i++)
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		int cnt[3]={0,1,2};
		int sigma=0;
		ans=-1;
		for(int i=1;i<=n;i++)
		{
			int ma=0,maval=a[i][0];
			for(int j=1;j<=2;j++)
			{
				if(a[i][j]>=maval)
				{
					ma=j;
					maval=a[i][j];
				}
			}
			cnt[ma]++;
			sigma+=maval;
		}
		if(max(cnt[0],max(cnt[1],cnt[2]))<=n/2)
			ans=sigma;
		solve(0),solve(1),solve(2);
		printf("%d\n",ans);
	}
}
