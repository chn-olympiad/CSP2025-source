#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],h[500005],zz,sz,da;
struct qjj
{
	ll l,r;
}qj[1000005];
ll qu(ll x,ll y){return h[y]^h[x-1];}
bool cmp(qjj x,qjj y){return x.r<y.r;}
void sol_1000()
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			if(qu(i,j)==k)
			{
				qj[++zz].l=i,qj[zz].r=j;
			}
		}
	}
	sort(qj+1,qj+zz+1,cmp);
	sz=qj[1].r;
	for(ll i=2;i<=zz;i++)
	{
		if(qj[i].l>sz)
		{
			sz=qj[i].r,da++;
		}
	}
	cout<<da+1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);h[i]=h[i-1]^a[i];
	}
	sol_1000();
	
	return 0;
}
