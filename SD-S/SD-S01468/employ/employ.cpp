#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
char s[510];
int c[510];
int p[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	scanf("%lld",&c[i]);
	int num=1;
	for(int i=1;i<=n;i++){
		p[i]=n-i+1;
		num*=i;
	}
	int ans=0;
	for(int T=1;T<=num;T++){
		next_permutation(p+1,p+n+1);
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(s[i]=='0'){
				cnt++;
			}
			else
			sum++;
		}
		if(sum>=m)
		ans++;
	}
	printf("%lld",ans%mod);
	return 0;
}
