#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
long long sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		sum[i]=sum[i-1] xor a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(abs(sum[j]-sum[i-1])==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
