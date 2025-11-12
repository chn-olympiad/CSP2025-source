#include<bits/stdc++.h>
#define MD 998244353
using namespace std;
long long n,ans;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	long long al=0,mx=-1,fg=0;
	for(long long i=0;i<(1<<n);i++){
		al=0,mx=-1,fg=0;
		for(long long j=1,cnt=i;j<=n;j++,cnt/=2){
			if(cnt%2==1){
				fg++;
				al+=a[j];
				mx=max(mx,a[j]);
			}
		}
		if(fg>=3 and al>2*mx){
			ans++;
			ans%=MD;
		}
		
	}
	printf("%lld",ans);
	return 0;
}