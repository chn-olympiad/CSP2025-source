#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],now,lst[1<<21],f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<1<<20;i++)lst[i]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		now^=a[i];
		f[i]=f[i-1];
		if(~lst[now^k])f[i]=max(f[i],f[lst[now^k]]+1);
		lst[now]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}
