#include <bits/stdc++.h>
using namespace std;
int n,k,sum[500005],a[500005],ans,f[500005];//k<1100000
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==k)
			f[i]=1;
		sum[i]=sum[i-1]^a[i];
	}
	for (int i=2;i<=n;i++){
		f[i]=f[i-1]+f[i];
		for (int j=1;j<i;j++){
			if ((sum[i]^sum[j-1])==k)
				f[i]=max(f[i],f[j-1]+1);
		}
	}
	printf("%d",f[n]);
	fclose(stdin);
	fclose(stdout);
}
