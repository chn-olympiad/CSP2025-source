#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,b[511],c[511];
char s[511];
bool t[511];
long long ans=0;
inline void dfs(int x){
	if(x==n+1){
		int cnt=0,res=0;
		for(int i=1;i<=n;i++)
			if(cnt>=c[b[i]]||s[i]=='0')cnt++;
			else res++;
		ans+=(res>=m);ans%=p;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!t[i]){
			t[i]=1;
			b[x]=i;
			dfs(x+1);
			t[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
