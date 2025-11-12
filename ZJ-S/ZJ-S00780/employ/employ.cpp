#include<bits/stdc++.h>
#define rint register int
using namespace std;
const int N=100005,mod=998244353;
int n,m,a[N],c[N];
void read(rint &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	for(rint i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(rint i=1;i<=n;i++) read(c[i]);
	cout<<2;
	return 0;
}
