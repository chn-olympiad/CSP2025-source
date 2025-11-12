#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf
#define mod
#define maxn 5005
#define int long long
int n,m,c[maxn],ls[maxn];
char s[maxn];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]); 
		ls[i]=i;
	}
	int ans=0;
	do{
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			int id=ls[i];
			if(c[id]<=cnt||s[i]=='0'){
				cnt++;continue;
			}
			tot++;
		}
		ans+=(tot>=m);
	}while(std::next_permutation(ls+1,ls+n+1)); 
	printf("%lld\n",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/

