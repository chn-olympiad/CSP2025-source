#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1005];
int p[1005],c[1005];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	bool S3=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') S3=0;
	}
	if(S3){//WA
		ll ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	ll ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[p[i]]) cnt++;
		}
		if(n-cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%lld\n",ans%mod);
	return 0;
}