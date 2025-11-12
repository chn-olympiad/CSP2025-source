#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define M 5010
#define p 133331
#define mod 998244353
#define ll long long
int n,m,len,lenn;
map<ll,ll> mp1,mp2;
char s1[M][M],s2[M][M];
char t1[N],t2[N];
ll a[N],cnt;
void init(int n)
{
	a[0]=1;
	for (int i=1;i<=n;i++)
	{
		a[i]=a[i-1]*p%mod;
	}
}
ll hs(char s[],int l,int r,int t)
{
	// l,r:in s pos
	// t:in hash pos
	ll res=1;
	for (int i=l,j=t;i<=r;i++,j++)
	{
		res=res*(s[i]-'a'+1)%mod*a[j]%mod;
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init(N-5);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s1[i]+1);
		scanf("%s",s2[i]+1);
		len=strlen(s1[i]+1);
		mp1[hs(s1[i],1,len,1)]=i;
	}
	for (int i=1;i<=m;i++)
	{
		mp2.clear();
		cnt=0;
		scanf("%s",t1+1);
		scanf("%s",t2+1);
		len=strlen(t1+1);lenn=strlen(t2+1);
		if (len!=lenn)
		{
			printf("0\n");
			continue;
		}
		for (int l=1;l<=len;l++)
			for (int r=l;r<=len;r++)
			{
				ll t=hs(t1,l,r,1);
				if (mp1[t]&&!mp2[t])
				{
					ll nw=hs(t1,1,l-1,1)*hs(s2[mp1[t]],1,r-l+1,l)%mod*hs(t1,r+1,len,r+1)%mod;
					if (nw==hs(t2,1,len,1))
					{
						cnt++;
						mp2[t]=1;
						break;
					}
				}
			}
		printf("%lld\n",cnt);
	}
	//system("fc .out .ans");
	return 0;
}
