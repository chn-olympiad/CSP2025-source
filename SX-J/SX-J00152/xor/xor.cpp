#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],t,sum,t1,bl=-100,f;
struct myxor{ll l,r;}s[500005];
struct ans{ll l,r;}ans[500005];
bool cmp(myxor x,myxor y)
{
	if((x.r-x.l)!=(y.r-y.l)) return (x.r-x.l)<(y.r-y.l);
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {cin>>a[i];if(a[i]!=1) f=1;}
	if(!f&&!k) {cout<<n/2;return 0;}
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
	if((a[i]^a[j])==k&&i!=j||i==j&&a[i]==k) s[++t].l=i,s[t].r=j;
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=t;i++) if(s[i].l>bl) sum++,bl=s[i].r;
//	{
//		bool z=0;
//		for(int j=1;j<=t1;j++) if(s[i].r>=ans[j].l||s[i].l<=ans[j].r) z=1;
//		if(!z) sum++,ans[++t1].l=s[i].l,ans[t1].r=s[i].r;
//	}
	cout<<sum;
	return 0;
}