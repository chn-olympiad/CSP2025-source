//10:10 maybe AK
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5100;
const int TT=998244353;
int n,ans,a[maxn],cnt[maxn],cur;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int r=a[n]+10;
	cnt[0]=1;
	for(int i=2;i<=n;i++){
		cur=(cur*2)%TT;
		for(int j=r;j>=0;j--){
			int x=j+a[i-1];
			if(x>r)cur=(cur+cnt[j])%TT;
			else cnt[x]=(cnt[x]+cnt[j])%TT;
		}
		ans=(ans+cur)%TT;
		for(int j=r;j>a[i];j--)ans=(ans+cnt[j])%TT;
	}
	cout<<ans;
	return 0;
}

