#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
string s;
long long n,m,fl=1;
long long ans;
long long f[505],jc[505],c[505],yi[505],tong[505];
void dfs(long long wei,long long xuan){
	if(wei>n)return;
	if(xuan==m){
		ans+=jc[n-wei];
		ans%=mod;
		return;
	}
	long long cishu=wei-xuan;
	for(long long i=1;i<=n;i++)
	{
		if(f[i]==0){
			f[i]=1;
			if(s[wei]=='1'&&c[i]>cishu)
				dfs(wei+1,xuan+1);
			else dfs(wei+1,xuan);
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	long long ls=s.size()-1;
	jc[0]=1,jc[1]=1;
	long long zhaoren=0;
	for(long long i=0;i<=ls;i++)
		if(s[i]=='1')zhaoren++,yi[zhaoren]=i;
	if(zhaoren<m){
		printf("0\n");
		return 0;
	}
	for(long long i=2;i<=500;i++){
		jc[i]=(jc[i-1]*i)%mod;
//		cout<<jc[i]<<' ';
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);	
		tong[c[i]]++;		
	}
	for(long long i=1;i<=500;i++){
		tong[i]+=tong[i-1];
	}
	long long jll=0;
	if(n<=18){
		dfs(0,0);
	}
	else{
		long long chengji=1;
		for(long long i=1;i<=zhaoren;i++){
			ans+=chengji*jc[n-i]*(tong[500]-tong[yi[i]-1])%mod;
			chengji=chengji*(tong[yi[i]-1]-jll)%mod;
			jll++;
			ans%=mod;
			chengji%=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
