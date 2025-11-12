#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],cnt,num[500005];
struct node{
	long long l,r;
}v[1000005];
bool cmp(node x,node y)
{
	if(x.r==y.r)return x.r-x.l<y.r-y.l;
	else return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)flagA=0;
		if(a[i]!=1&&a[i]!=0)flagB=0;
	}
	if(flagA){
		printf("%lld",n/2);
		return 0;
	}else
	if(n<=2005){
		for(int i=1;i<=n;i++){
			num[i]=num[i-1]^a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++){
				int c=num[j]^num[i-1];
				if(c==k)
				{
					cnt++;
					v[cnt].l=i;
					v[cnt].r=j;
				}
			}
		}
		sort(v+1,v+cnt+1,cmp);
		int sum=0,r=0;
		for(int i=1;i<=cnt;i++){
			if(v[i].l>r){
				sum++,r=v[i].r;
			}
		}
		printf("%lld",sum);
	}
	return 0;
}
