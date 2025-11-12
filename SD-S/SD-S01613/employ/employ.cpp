#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char obuf[1000010],*p3=obuf;
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf,1,1000000,stdout),*p3++=x)
void write(int x){
	static char stk[10];
	int top=0;
	do stk[top++]=x%10|48;while(x/=10);
	while(top)pc(stk[--top]);
}
const int p=998244353;
int MOD(const int&x){
	return x<p?x:x-p;
}
char S[510];
int a[510],f[270000][20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,N,x,ans=0;
	cin>>n>>m>>S+1;
	for(int i=0;i<n;++i)cin>>a[i];
	if(n<19){
		N=1<<n;
		f[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int s=0;s<N;++s)if(__builtin_popcount(s)==i-1){
				for(int j=0;j<i;++j){
					for(int k=0;k<n;++k)if(!(s>>k&1)){
						x=a[k]<=j||S[i]=='0';
						f[s|1<<k][j+x]=MOD(f[s|1<<k][j+x]+f[s][j]);
					}
				}
			}
		}
		for(int i=0;i<=n-m;++i)ans=MOD(ans+f[N-1][i]);
		printf("%d",ans);
	}
	return 0;
}
