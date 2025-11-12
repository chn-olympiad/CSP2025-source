#include<iostream>
#define int long long
using namespace std;
int n,k,a[500005],sum[500005],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	int le=0;
	for(int r=1;r<=n;r++){
		for(int l=le;l<r;l++){
			if((sum[l]^sum[r])==k){
				ans++;
				le=r;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
