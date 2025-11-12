#include<bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long n,m,c[510],d[510],ans = 0,b[510];
char s[510];
inline void dfs(long long top){
	if(top==n){
		long long sum = 0,num = 0;
		for(int i = 1;i<=n;i++){
			if(sum>=c[d[i]]){
				sum++;
				continue;
			}
			if(s[i]=='1') num++;
			else sum++;
		}
		if(num>=m) ans++,ans%=p;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(b[i]) continue;
		b[i] = 1,d[top+1] = i;
		dfs(top+1);
		b[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	scanf("%s",s+1);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
