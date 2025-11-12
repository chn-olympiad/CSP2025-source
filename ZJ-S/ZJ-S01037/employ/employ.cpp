#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
struct node{
	int t,c;
};
int n,m,ans=0,c[1001],p[1001],d[1001];
string s;
void dfs(int k){
	if(k==n){
		int cnt=0,num=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i]=='0')cnt++;
		}
		if(n-cnt>=m)ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1)continue;
		p[k+1]=i;
		d[i]=1;
		dfs(k+1);
		p[k+1]=0;
		d[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int w=1;
	for(int i=1;i<s.length();i++){
		if(s[i]!='1')w=0;
	}
	if(w==1){
		ans=1;
		for(int i=n;i>=1;i--){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==m){
		cout<<0;
		return 0;
	}
	if(m==1){
		int cnt=0,a[10001],num=0;
		for(int i=1;i<s.length();i++){
			if(s[i]=='1'){
				for(int j=1;j<=n;j++){
					if(c[j]>i-1)cnt++;
				}
				num++;
				a[num]=n-cnt;
				for(int j=n-num;j>=1;j--){
					cnt=(cnt*j)%mod;
				}
				for(int j=1;j<=num;j++){
					cnt=(cnt*a[j])%mod;
				}
				ans=(ans+cnt)%mod;
				cnt=0;
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
