#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e2+5,mod=998244353;
int n,m,c[N],mark[25],a[25];
char s[N];
ll ans,fac[N];
void dfs(int k){
	if(k>n){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||cnt>=c[a[i]]) cnt++;
		if(n-cnt>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			a[k]=i;
			mark[i]=1;
			dfs(k+1);
			mark[i]=0;
		}
	}
}
void solve1(){
	ll sum[N];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	for(int i=1;i<=n;i++){
		cout<<i<<" ";
		if(s[i]=='0') continue;
		ll cnt=0,p=0;
		for(int j=1;j<=n;j++)
			if(c[i]>i-1) cnt++;
		for(int j=1;j<i;j++){
			sum[j]=0;
			if(s[j]=='0') continue;
			for(int k=1;k<=n;k++){
				if(c[k]<=j-1) sum[j]++;
			}
			if(sum[j]==0) sum[j]=-1;
		}
		for(int j=1;j<i;j++){
			if(sum[j]==-1){
				cnt=0;
				break;
			}
			if(sum[j]==0) continue;
			cnt*=sum[j]-p;
			cnt%=mod;
			p++;
		}
		p++;
		cnt*=fac[n-p];
		if(i<=10)
		cout<<cnt<<endl;
		cnt%=mod;
		ans+=cnt;
		ans%=mod;
	}
}
void solve2(){
	dfs(1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(m==1){
		solve1();
	}
	else if(n<=18){
		solve2();
	}
	printf("%lld",ans);
	return 0;
}
