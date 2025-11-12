#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5,M=2e6+5;
int n,k,a[N],sum[N],num[M],ans,w[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=0;i<=n;i++){
		int tmp=sum[i]^k;
		if(num[tmp]) {
			ans++;
			for(int j=1;j<=cnt;j++) num[w[j]]=0;
			cnt=0;
		}
		w[++cnt]=sum[i];
		num[sum[i]]=1;
	}
	printf("%d",ans);
	return 0;
}