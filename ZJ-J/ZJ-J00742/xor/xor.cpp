#include<bits/stdc++.h>
const int N=2e5+5;
using namespace std;
int n,k,m,ans;
int l[N],r[N],xo[N];
struct node
{
	int l,r;
}a[N];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int t;
	for(int i=1;i<=n;++i) scanf("%d",&t),xo[i]=xo[i-1]^t;
	for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j)
	if((xo[j]^xo[i-1])==k) a[++m].l=i,a[m].r=j;
	sort(a+1,a+m+1,cmp);
	int now=0;
	for(int i=1;i<=m;++i)
	if(a[i].l>now) ans++,now=a[i].r;
	cout<<ans<<"\n";
	return 0;
}//60pts
