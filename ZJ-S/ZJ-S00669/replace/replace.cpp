#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,pair<int,int> > pd;
const int N=5e6+5;
const ull p=131;
int n,q,t,head,tail,cnt=1,ans;
char a[N],b[N];
ull hsh[N];
map<ull,int> mp;
map<pd,int> tr;
map<int,int> val,fa;
inline ull pk(ull a,ull b)
{
	ull ret=1;
	while(b)
	{
		if (b&1)ret=ret*a;
		a=a*a,b>>=1;
	}
	return ret;
}
inline ull get(int l,int r)
{
	return hsh[r]-hsh[l-1]*pk(p,2*(r-l+1));
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int l=1;l<=n;l++)
	{
		scanf("%s%s",a+1,b+1);
		t=strlen(a+1);
		ull k=0;
		for (int i=1,j=1;i<=t;i++)
		{
			k=k*p*p+(a[i]-'a'+1)*p+(b[i]-'a'+1);
			if (tr.find((pd){j,(pair<int,int>){a[i]-'a'+1,b[i]-'a'+1}})==tr.end())tr[(pd){j,(pair<int,int>){a[i]-'a'+1,b[i]-'a'+1}}]=++cnt,mp[k]=cnt,fa[cnt]=j;
			j=tr[(pd){j,(pair<int,int>){a[i]-'a'+1,b[i]-'a'+1}}];
			if (i==t)val[j]++;
		}
		for (int j=1;j<=t;j++)a[j]=b[j]=0;
	}
	for (int i=2;i<=cnt;i++)val[i]+=val[fa[i]];
	for (int l=1;l<=q;l++)
	{
		ans=0;
		scanf("%s%s",a+1,b+1);
		t=strlen(a+1);
		for (int i=1;i<=t;i++)hsh[i]=hsh[i-1]*p*p+(a[i]-'a'+1)*p+b[i]-'a'+1;
		int head,tail;
		for (head=1;head<=t && a[head]==b[head];head++);
		for (tail=n;tail>=1 && a[tail]==b[tail];tail--);
		for (int j=1;j<=head;j++)
		{
			int l=j,r=t,pos=0;
			while (l<=r)
			{
				int mid=(l+r)>>1;
				if (mp.find(get(j,mid))==mp.end())r=mid-1;
				else pos=mid,l=mid+1;
			}
			if (pos)ans+=val[mp[get(j,pos)]];
			if (j<=tail-1)
			{
				l=j,r=tail-1,pos=0;
				while (l<=r)
				{
					int mid=(l+r)>>1;
					if (mp.find(get(j,mid))==mp.end())r=mid-1;
					else pos=mid,l=mid+1;
				}
				if (pos)ans-=val[mp[get(j,pos)]];
			}
		}
		printf("%d\n",ans);
		for (int j=1;j<=t;j++)a[j]=b[j]=0;
	}
	return 0;
}
