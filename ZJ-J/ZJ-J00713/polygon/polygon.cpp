#include<bits/stdc++.h>
using namespace std;
const long long maxn=5005;
long long read(){
	long long ret=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9')f=(ch=='-')?-f:f,ch=getchar();
	while('0'<=ch&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
long long n,m,a[maxn],ans;
long long st[maxn][30];
long long search(long long l,long long r){
	long long len=r-l+1;
	long long d=log2(len);
	return max(st[l][d],st[r-(1<<d)+1][d]);
}
long long max(long long x,long long y){
	return x>y?x:y;
}
void dfs(long long sum,long long maxl,long long l,long long s){
	ans%=998244353;
	if(s>2&&(sum-maxl)>maxl)ans++;
	if(l==n)return;
	for(long long i=l+1;i<=n;i++){
		dfs(sum+a[i],max(maxl,a[i]),i,s+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++)a[i]=read();
	if(n<=2){printf("0\n");return 0;}
	if(n==3){printf("%d\n",((a[1]+a[2]+a[3]-max(a[1],max(a[2],a[3])))>max(a[1],max(a[2],a[3])))?1:0);return 0;}
	dfs(0,0,0,0);
	ans%=998244353;
	printf("%lld\n",ans);
}
