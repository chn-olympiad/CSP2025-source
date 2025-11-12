#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005
using namespace std;
int read()
{
	int fl=1,x=0;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')fl=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*fl;
}
int n,cnt[5],val[N],m;
struct po{
	int val,id;
}num[N][5];
bool cmp(po a,po b)
{
	return a.val>b.val;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		m=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		n=read();
		int Ans=0;
		for(int i=1;i<=n;i++)
		{
			num[i][1].val=read();
			num[i][2].val=read();
			num[i][3].val=read();
			num[i][1].id=1;num[i][2].id=2;num[i][3].id=3;
			sort(num[i]+1,num[i]+4,cmp);
			Ans+=num[i][1].val;
			cnt[num[i][1].id]++;
		}
		int k=3;
		if(cnt[1]>n/2)k=1;
		if(cnt[2]>n/2)k=2;
		for(int i=1;i<=n;i++)
			if(num[i][1].id==k)
				val[++m]=num[i][1].val-num[i][2].val;
		sort(val+1,val+1+m);
		for(int i=1;i<=cnt[k]-n/2;i++)
			Ans-=val[i];
		cout<<Ans<<'\n';
	}
	return 0;
}
