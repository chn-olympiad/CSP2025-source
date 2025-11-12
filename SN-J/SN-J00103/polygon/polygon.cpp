#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5008];
int sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(sum<=a[n]*2){
		putchar('0');
		return 0;
	}
	for(int i=1;i<=n-2;++i){
		for(int j=3;j<=n;++j){
			int cnt=0,k=i;
			while(k<=i+j-1){
				cnt+=a[k++];
			}
			if(k){
				if(cnt>a[k]*2){
					++ans;
					ans%=MOD;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
