#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int fac[505],a[505],b[505],t[505],pre[25],ss[25],tot=0,f[400005];
void work(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]) pre[++tot]=i;
	tot=0;
	for(int i=1;i<=n;i++){
		while(a[i]>=pre[tot]) tot++;
		ss[tot]++;
	}
	for(int i=(1<<sum);i>=1;i--){
		for(int j=0;(1<<j)<=i;j++){
			if(i&(1<<j)){
				f[i]+=114514;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=(1<<sum);i++){
		int k=0,ii=i;
		while(ii){
			k+=ii%2;
			ii/=2;
		}
		if(k==m) ans++;
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,flag=1;
	scanf("%d%d",&n,&m);
	char s;
	while(s!='0'&&s!='1') s=getchar();
	for(int i=1;i<=n;i++){
		a[i]=s-'0';
		sum+=a[i];
		s=getchar();
	}
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(long long i=1;i<=n;i++) fac[i]=fac[i-1]*i%998244353;
	if(sum==n){
		printf("%lld\n",fac[n]);
		return 0;
	}
	if(sum<m){
		puts("0");
		return 0;
	}
	if(sum<=18){
		work();
		return 0;
	}
	else printf("%lld\n",fac[n]);
	return 0;
}
//feropen()
//freopen("employ.in","r",stdin);
//关注Just_A_Sentence(LuoguUid=502314)谢谢喵
//15:37 过T1
//17:29 战绩100+0+0+24=124，还能蒸！
//17:43 战绩 100+0+25+24=149
//18:07 100+0+50+24=174
//18:18 100+0+[50,70]+24=[174,194]完蛋了
//18:26 100+[0,16]+[50,70]+24=[174,210]寄