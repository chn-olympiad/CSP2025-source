#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const long long N=505;
long long n,m,ans,s[N],c[N],sx[N];
string S;
bool check(){
	long long cnt1=0,cnt2=0;
	for(long long i=1;i<=n;i++){
		long long id=sx[i];
		if(cnt1>=c[id]){cnt1++;continue;}
		if(s[i]==0) cnt1++;
		else cnt2++;
		if(cnt2==m) return 1;
	}return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);cin>>S;S=" "+S;
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		s[i]=S[i]-'0';
		cnt+=(s[i]==1);
	}
	if(cnt<m) return printf("0"),0;cnt=0;
	for(long long i=1;i<=n;i++) scanf("%lld",c+i),cnt+=(c[i]==0);
	if(n-cnt<m) return printf("0"),0;
	for(long long i=1;i<=n;i++) sx[i]=i;
	do{
		if(check()) ans=(ans+1)%mod;
	}while(next_permutation(sx+1,sx+n+1));
	printf("%lld",ans);
	return 0;
}

