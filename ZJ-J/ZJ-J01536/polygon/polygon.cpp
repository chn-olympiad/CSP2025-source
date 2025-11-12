#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],sum[5005],b[5005],c[5005],d[5005],ans,maxpf,mod=998244353;
bool nqm1[5005],nqm2[5005];
ll maxl(ll x,ll y){return x>y?x:y;}
ll C(ll n,ll m){
	ll s=1;
	if(n==m)return 1;
	if(m==n-1)return n;
	if(m==1)return n;
	for(int i=1;i<=n;i++){
		s=s*i;
		for(int j=2;j<=(n-m);j++){
			if(s%j==0&&!nqm1[j]){
				s/=j;
				nqm1[j]=true;
			}
		}
		for(int j=2;j<=m;j++){
			if(s%j==0&&!nqm2[j]){
				s/=j;
				nqm2[j]=true;
			}
		}
		s%=mod;
	}
	return s;
}
void dfs(int m,int k){
	if(k>m){
		ll s=0;
		for(int j=1;j<=m;j++)s+=c[j];
		if(s>2*c[m])ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]&&i>d[k-1]){
			c[k]=a[i];
			d[k]=i;
			b[i]=1;
			dfs(m,k+1);
			d[k]=0;
			b[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxpf=maxl(maxpf,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	if(maxpf==1){
		for(ll i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++)dfs(i,1);
	cout<<ans;
	return 0;
}