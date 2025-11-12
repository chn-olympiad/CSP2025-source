#include<bits/stdc++.h>
using namespace std;
const int N=5050;
const int m=5001;
const long long mod=998244353;
int n,a[N],x,mx;
long long ans,b[N],s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	b[0]=1;
	for(int i=1;i<=n;i++){
		ans+=s[a[i]+1];
		ans%=mod;
		for(int j=mx;j>=0;j--){
			x=min(j+a[i],m);
			b[x]+=b[j];
			b[x]%=mod;
			s[x]=s[x+1]+b[x];
			s[x]%=mod;
		}
		mx=min(mx+a[i],m);
	}
	printf("%lld",ans);
	return 0;
}
