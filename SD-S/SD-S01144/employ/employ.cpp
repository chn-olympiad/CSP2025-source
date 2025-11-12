#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500+10;
const int mod=998244353;
int n,m,ans;
char s[N];
int t[N],c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),t[i]=i;
	do{
		int tot=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[t[i]]<=tot) tot++;
		}
		if(n-tot>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		}
	}while(next_permutation(t+1,t+1+n));
	printf("%d",ans);
	return 0;
}
