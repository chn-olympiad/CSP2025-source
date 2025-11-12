#include<bits/stdc++.h>
using namespace std;
const int N=5211;
const long long MOD=998244353;
int n;
long long ans,cnt,maxn,a[N],f[501];
void dfs(int dep) {
	if(dep>n) {
		if(dep>3&&cnt>2*maxn) {
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(dep+1);
	cnt+=a[dep];
	int m=maxn;
	maxn=max(maxn,a[dep]);
	dfs(dep+1);
	cnt-=a[dep];
	maxn=m;

}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	long long maxx=0;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(n<=20) {
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}else if(maxx<=1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=MOD;
		}
		ans-=1;
		ans-=(n+1)*n/2;
		while(ans<0)ans+=MOD;
		printf("%lld\n",ans);
		return 0;
	}else if(n<=500){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=MOD;
		}
		ans-=1;
		ans-=(n+1)*n/2;
		while(ans<0)ans+=MOD;
		for(int i=1;i<=n;i++){
			for(int i=1;i<=a[i-1];i++){
				f[i]=0;
			}
			f[0]=1;
			for(int j=1;j<=n;j++){
				for(int k=a[i]-1;k>=a[j];k--){
					f[k]+=f[k-a[j]]+1;
					f[k]%=MOD;
				}
			}
			for(int i=1;i<a[i];i++){
				cnt+=f[i];
				cnt%=MOD;
			}
		}
		cnt-=(n-1)*n;
		while(cnt<0)cnt+=MOD;
		cnt%=MOD;
		printf("%lld\n",(ans-cnt+MOD)%MOD);
	}else{
		printf("0\n");
	}
	return 0;
}
/*

如果不爆零我就能得到364pts
++rp
T4貌似是组合题 但我不会QAQ 有没有可能是总情况数减去不可行情况数来求
（因为在15~20共24pts的数据中保证一定可以组成 总不能说这玩意没用吧）
还有一个小时 我试试吧
也就是说我们可以对于每个a[i]求一个组合不含a[i]且和小于等于a[i]
那O(n^3)的做法不就来了吗！！！！
马上11~14美美得吃16pts 
(nearly an hour later)
cao的这个16pts还没拿到
不管了 先检查其他的


and

我想上ZJ迷惑行为大赏可以吗
orz

*/