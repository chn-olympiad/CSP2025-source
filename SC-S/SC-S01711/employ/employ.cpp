#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[505],p=998244353,b[505],ans;
char s[505],z;
bool v[505];
void dfs(int x){
	if(x==n+1){
		int sum=0,fq=0;
		for(int i=1;i<=n;i++){
			if(c[b[i]]<=fq){
				fq++;
				continue;
			}
			if(s[i]=='1')	sum++;
			else	fq++;
		}
		if(sum>=m)	ans++;
		ans%=p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			b[i]=x;
			dfs(x+1);
			v[i]=0;
			b[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	scanf("%c",&z);
	for(int i=1;i<=n;i++)
		scanf("%c",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}