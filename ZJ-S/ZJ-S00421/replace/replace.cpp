#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+10,M=5e6+10,B=131;
ll n,q,ans;
ull b[M],h1[M],h2[M],c[N],d[N];
string t1,t2,s[N][2];
ull get1(ll l,ll r)
{
	if(l>r)return 0;
	return h1[r]-h1[l-1]*b[r-l+1];
}
ull get2(ll l,ll r)
{
	if(l>r)return 0;
	return h2[r]-h2[l-1]*b[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	b[0]=1;
	for(int i=1; i<M; ++i)
		b[i]=b[i-1]*B;
	cin>>n>>q;
	for(int i=1; i<=n; ++i)
	{
		cin>>s[i][0]>>s[i][1];
		for(int j=0; j<s[i][0].size(); ++j)
			c[i]=c[i]*B+s[i][0][j];
		for(int j=0; j<s[i][1].size(); ++j)
			d[i]=d[i]*B+s[i][1][j];
	}
	while(q--)
	{
		cin>>t1>>t2;
		ll len=t1.size();
		for(int i=0; i<len; ++i)
			h1[i]=h1[i-1]*B+t1[i];
		for(int i=0; i<len; ++i)
			h2[i]=h2[i-1]*B+t2[i];
		ll ans=0;
		for(int i=1; i<=n; ++i)
		{
			ll tmp=s[i][0].size();
			ull now=c[i],nw=d[i];
			for(int j=0; j+tmp-1<len; ++j)
			{
				if(get1(j,j+tmp-1)==now)
				{
					if(get2(j,j+tmp-1)==nw&&get2(0,j-1)==get1(0,j-1)
					&&get2(j+tmp,len-1)==get1(j+tmp,len-1))
					{
						ans++;
						if(n>=500&&q>=500)break;
					}	
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}