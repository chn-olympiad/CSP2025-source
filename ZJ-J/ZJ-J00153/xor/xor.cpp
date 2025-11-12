#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
}a[500005];
int n,k,cnt,ans,s[500005],lst[5000005];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
//	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(lst,-1,sizeof lst);
	lst[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),
		s[i]^=s[i-1],
		a[++cnt]={lst[k^s[i]]+1,i},
		lst[s[i]]=i;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1,j=0;i<=n;i++)
		j<a[i].l?ans++,j=a[i].r/*,printf("%d %d\n",a[i].l,a[i].r)*/:0;
	printf("%d",ans);
	return 0;
}
