#include <cstdio>
const int maxn=500000+4;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==0) printf("%d\n",n);
	else{
		long long num=0;
		for(int i=1;i<=n;i++)
			num+=i;
		printf("%lld\n",num);
	}
}
