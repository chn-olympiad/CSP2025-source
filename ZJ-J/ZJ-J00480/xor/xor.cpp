#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],f[500005];
int maxx[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(maxx,0xbf,sizeof(maxx)); maxx[0]=0;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],maxx[s[i]^k]+1);
		maxx[s[i]]=max(maxx[s[i]],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}
