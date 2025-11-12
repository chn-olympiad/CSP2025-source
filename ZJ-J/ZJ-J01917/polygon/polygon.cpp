#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=5e3+10;
const int MO=998244353;
int a[N];
int fac[N];
int inv[N];
int qpow(int a,int b){
	int res=1;
	while (b){
		if (b&1){
			res=(res*a)%MO;
		}
		b>>=1;
		a=(a*a)%MO;
	}
	return res;
}
void solve1(){
	fac[0]=1;
	for (int i=1; i<=n; i++){
		fac[i]=(fac[i-1]*i)%MO;
	}
	for (int i=0; i<=n; i++){
		inv[i]=qpow(fac[i],MO-2);
	}
	int ans=0;
	for (int i=3; i<=n; i++){
		ans+=((inv[i]*fac[n])%MO*inv[n-i]);
		ans%=MO;
	}
	cout<<ans<<"\n";
}
bool vis[N];
int cnt1=0;
void dfs(int st,int maxx,int now,int val,int tmp,int pre){
	if (now==st){
		if (val>maxx){
			cnt1++;	
		}
		return ;
	}
	for (int i=pre; i<tmp; i++){
		if (!vis[i]){
			vis[i]=1;
			dfs(st,maxx,now+1,val+a[i],tmp,i);
			vis[i]=0;
		}
	}
}
void solve2(){
	int ans=0;
	for (int i=3; i<=n; i++){
		for (int j=2; j<=i-1; j++){
			cnt1=0;
			dfs(j,a[i],0,0,i,1);
			ans+=cnt1;
			ans%=MO;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool fl1=1;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		if (a[i]!=1){
			fl1=0;
		}
	}
	sort(a+1,a+n+1);
	if (fl1){
		solve1();
	}else if (n<=50){
		solve2();
	}else{
		solve1();
	}
	return 0;
}
