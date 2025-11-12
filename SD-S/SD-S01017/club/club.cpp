#include<bits/stdc++.h>
using namespace std;
const long long mod1=998244353;
const long long mod2=1000000007;
const long long inf=0x3f3f3f3f3f3f3f3f;
const long long MAXN=100011;
struct node{
	pair<long long,long long>num[4];
}a[MAXN];
long long t,n;
long long qwq[4];
long long sta[MAXN],tot;
long long ans;

void init();
void domemset();
long long read();
void write(long long x);

bool cmp1(pair<long long,long long>x,pair<long long,long long>y)
{
	return x.first>y.first;
}
bool cmp2(node x,node y)
{
	return x.num[1]>y.num[1];
}
bool cmp3(long long x,long long y)
{
	return x<y;
}

void fun()
{
	domemset();
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
			a[i].num[j].first=read(),a[i].num[j].second=j;
		sort(a[i].num+1,a[i].num+4,cmp1);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
		ans+=a[i].num[1].first,qwq[a[i].num[1].second]++;
	long long tmpid=0,tmpsum=0;;
	for(int i=1;i<=3;i++)
		if(qwq[i]>n/2)
			tmpid=i,tmpsum=qwq[i]-n/2;
	if(tmpid!=0)
	{
		for(int i=1;i<=n;i++)
			if(a[i].num[1].second==tmpid)
				sta[++tot]=a[i].num[1].first-a[i].num[2].first;
		sort(sta+1,sta+tot+1,cmp3);
		for(int i=1;i<=tmpsum;i++)
			ans-=sta[i];
	}
	write(ans),putchar('\n');
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(NULL));
	init();
	t=read();
	for(int i=1;i<=t;i++)
//	while(1)
		fun();
	return 0;
}


void init()
{

	return ;
}
void domemset()
{
	tot=0;
	qwq[1]=qwq[2]=qwq[3]=0;
	ans=0;
	return ;
}
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>=10)
		write(x/10);
	putchar((x%10)^'0');
	return ;
}

