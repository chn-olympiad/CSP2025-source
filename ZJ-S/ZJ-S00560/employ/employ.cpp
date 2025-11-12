#include<bits/stdc++.h>
using namespace std;
//16:04 4pts
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repn(x) rep(x,1,n)
#define per(x,y,z) for(int x=y;x>=z;x--)
const int N=509,mod=998244353;
int n,m,a[N],cnt=0,fac[N],b[N],vis[N],tmp[N],d[N];
int val1[N],val2[N];
char s[N];
int fastmi(int a,int b){
	if(b==0) return 1;
	if(b==1) return a;
	int k=fastmi(a,b/2)%mod;
	if(b&1) return k*k%mod*a%mod;
	return k*k%mod;
}
void sub15(){
	int ans=1;
	rep(i,1,n){
		if(s[i]=='0'){
			ans=0;	
		} 
	}
	rep(i,1,n){
		if(a[i]==0) ans=0;
	}
	ans=ans*fac[n];
	cout<<ans<<"\n";
}
bool check(){
	rep(i,1,n) tmp[i]=a[b[i]];
//	repn(i) cout<<tmp[i]<<" ";
//	cout<<"\n";
	int tt=0,cc=0;
	repn(i){
		if(s[i]=='0') tt++;
		else{
			if(tmp[i]-tt<=0) tt++;
			else cc++;
		}
	}
//	cout<<cc<<"\n";
	return cc>=m;
}
void dfs(int step){
	if(step==n+1){
		if(check()) cnt++;
		else{
			for(int i=1;i<=n;i++) cout<<b[i]<<" ";
			cout<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[step]=i;
			vis[i]=1;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int inv(int x){
	return fastmi(x,mod-2)%mod;
}
int P(int n,int m){
	return fac[n]*inv(fac[n-m])%mod;
}
/*
5 1
10000
0 1 2 3 3 
*/
void sub1214(){
	int ans=1;
	rep(i,1,n){
		d[i]=d[i-1]+1-(s[i]-'0');
	}
	rep(i,1,n) val1[a[i]]++;
	rep(i,1,n) val2[d[i]]++;
	per(i,n,1) val2[i]=val2[i+1]+val2[i];
	int used=0;
	for(int i=n;i>=1;i--){
		if(val1[i]==0) continue;
		if(val2[i]-used<val1[i]) ans=0;
		ans=ans*P(val2[i]-used,val1[i])%mod;
		used+=val1[i];
	}
	ans=(fac[n]-ans+mod)%mod;
	cout<<ans<<"\n";
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=1;
	rep(i,1,n) fac[i]=fac[i-1]*i%mod;
	repn(i) cin>>s[i];
	repn(i) cin>>a[i];
	if(n==m){
		sub15();
	}
	else if(n<=10){
		dfs(1);
		cout<<cnt<<"\n";
	}
	else if(m==1){
		sub1214();
	}
	return 0;
}
