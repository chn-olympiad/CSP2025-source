#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=500+10;
const int mod=998244353;
int n,m,c[maxn],cnt0,ans,cntc,cnt1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++){
		if(s[i]=='0') cnt0++;
		else break;
	}
	for(int i=0;i<n;i++)
		if(s[i]=='1') cnt1++;
	for(int i=1;i<=n;i++)
		if(c[i]>cnt0) cntc++;
	if(m==1){
		if(cntc==0){
			cout<<0<<endl;
			return 0;
		}
		ans=cntc%mod;
		for(int i=1;i<=n-1;i++)
			ans=((ans%mod)*(i%mod))%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(cnt1==n){
		if(cntc<m){
			cout<<0<<endl;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++)
			ans=((ans%mod)*(i%mod))%mod;
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
//命若繁星，望而不及。赞美【命运】。