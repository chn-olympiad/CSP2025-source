#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+10;
const int MOD = 998244353;

int n,ans,maxn,ma;
int a[N],sum[N];
int c[N][N];
int frc[N];

int ksm(int base,int powr=MOD-2){
	int res=1,num=base;
	while(powr){
		if(powr&1){
			res=((res%MOD)*(num%MOD))%MOD;
			res%=MOD;
		}
		num=((num%MOD)*(num%MOD))%MOD;
		powr>>=1;
	}
	return res%MOD;
}

int C(int x,int y){
	if(c[x][y]) return c[x][y];
	return c[x][y]=(frc[x]%MOD)*ksm((frc[y]%MOD)*(frc[x-y]%MOD)%MOD)%MOD;
}

void dfs(int x,int step,int cnt,int r,int l){
	if(step>=l){
		if(cnt>ma) ++ans;
		return;
	}
	for(int i=x;i<=r-l+step;i++){
		if(cnt+a[i]>ma){
			++ans;
			if(r-i-1>0) ans+=C(r-x-1,l-step);
			return;
		}
		dfs(i+1,step+1,cnt+a[i],r,l);
	}
}

void check(int x){
	for(int k=2;k<x;k++){
		for(int i=1;i<x-k+1;i++){
			dfs(i+1,1,a[i],x,k);
		}
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	frc[0]=1;
	for(int i=1;i<=n;i++){
		frc[i]=((frc[i-1]%MOD)*(i%MOD))%MOD;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(sum[i-1]<=a[i]) continue;
		ma=a[i];
		check(i);
	}
	cout<<ans;
	return 0;
}

//(frc[6]*ksm(frc[4]*frc[2]))%MOD
