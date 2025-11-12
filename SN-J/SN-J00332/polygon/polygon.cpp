#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e3+10,mod=998244353;
int n,a[MAXN],fac[MAXN],sum[MAXN],ans,cnt;
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int x,int y){
	return fac[x]*qpow(fac[y]*fac[x-y]%mod,mod-2)%mod;
}
int flag[MAXN];
void dfs(int x,int nedn,int num,int nedv,int val){
	if(x==1&&(num<nedn||val<nedv)) return ;
	if(num==nedn&&val>nedv){
		ans++;ans%=mod;
		return ;
	}
	for(int i=x-1;i>=1;i--){
		if(!flag[i]){
			flag[i]=1;
			dfs(i,nedn,num+1,nedv,val+a[i]);
			flag[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=3;j<=n;j++){
			dfs(j,i,1,2*a[j],a[j]);
		}
	}
	cout<<ans;
//	for(int i=3;i<=n;i++){
//		for(int j=2;j<i;j++){
//			for(int k=1;k<j;k++){
//				if(2*a[i]>=a[i]+a[j]+a[k]){
//					continue;
//				}
//				for(int l=sum;)
//				int sum=n-3,lj=0;
//				for(int l=0;l<=sum;l++){
//					lj+=C(sum,l);
//					lj%=mod;
//				}
//				cout<<i<<" "<<j<<" "<<k<<": "<<lj<<"\n";
//				ans+=lj;
//				cnt++;
//			}
//		}
//	}
//	cout<<ans<<" "<<cnt;
	return 0;
}
