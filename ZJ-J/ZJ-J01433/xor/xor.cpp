#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],cnt,ans,len,le;
struct node
{
	int l,r;
}d[500005];
struct nodee
{
	int l,r;
}p[500005];
bool cmp(node x,node y)
{
	if(x.r<y.r) return true;
	return false;
}
signed main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		cnt=a[i];
		if(cnt==k){
//			printf("%lld %lld %lld\n",i,j,cnt);
			d[++le].l=i;
			d[le].r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			cnt^=a[j];
			if(cnt==k){
//				printf("%lld %lld %lld\n",i,j,cnt);
				d[++le].l=i;
				d[le].r=j;
				break;
			}
		}
	}
	sort(d+1,d+le+1,cmp);
	for(int i=1;i<=le;i++){
//		printf("%lld %lld\n",d[i].l,d[i].r);
		bool flag=false;
		for(int j=1;j<=len;j++){
			if(d[i].l<=p[j].r){
				flag=true;
				break;
			}
		}
		if(!flag) p[++len].l=d[i].l,p[len].r=d[i].r;
	}
//	printf("\n");
//	for(int i=1;i<=len;i++) printf("%lld %lld\n",p[i].l,p[i].r);
	printf("%lld",len);
	return 0;
}
