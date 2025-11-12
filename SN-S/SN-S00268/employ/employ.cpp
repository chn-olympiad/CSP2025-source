//考号:SN-S00268  姓名:强小轩  学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
int n,m,c[505],cnt0,cnts,modd=998244353;
int s[505],cnt[505],sum[505],a[505],summ[505];
ll ans;
bool check(){
	int cntt=0,res=0;
	for(int i=1;i<=n;i++){
		if(cntt>=c[a[i]]){
			cntt++;
			continue;
		}
		if(!s[i])cntt++;
		else res++;
	} 
	return res>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
		if(s[i])cnts++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt0++;
		else cnt[c[i]]++;
	}
	if(min(cnts,n-cnt0)<m){
		cout<<0<<'\n';
		return 0;
	}
	if(m==n){
		ll res=1;
		for(int i=2;i<=n;i++){
			res=(res*i)%modd;
		}
		cout<<res<<'\n';
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+cnt[i];
		}
		ll res=0;
		for(int i=1;i<=n;i++){
			summ[i]=summ[i-1];
			if(!s[i])summ[i]++;
			if(s[i]){
				res+=sum[n]-sum[summ[i]];
				res%=modd;
			}
		}
		for(int i=1;i<n;i++){
			res=(res*i)%modd;
		}
		cout<<res<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=i;
	do{
		if(check()){
			ans++;
			ans%=modd;
		}
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<'\n';
	return 0;
}

































