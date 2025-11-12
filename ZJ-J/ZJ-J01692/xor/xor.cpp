#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	} 
	return f*x;
}
struct node{
	int l,r;
}len[500005];
bool operator <(node x,node y)
{
	return x.r<y.r;
}
int n,i,cnt,ans,k,rp;
ll a[500005],sum[500005];
map<ll,int>way; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();rp++;
	for(i=1;i<=n;++i)
	{
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	way[0]=0;
	for(i=1;i<=n;++i)
	{
		int need=sum[i]^k;
		if(way.count(need))
			len[++cnt]=(node){way[need]+1,i};
		way[sum[i]]=i;
	}
	sort(len+1,len+1+cnt);
	int last=0;
	for(i=1;i<=cnt;++i)
		if(len[i].l>last)
		{
			last=len[i].r;
			++ans;
		}
	cout<<ans;
	return 0;
}
