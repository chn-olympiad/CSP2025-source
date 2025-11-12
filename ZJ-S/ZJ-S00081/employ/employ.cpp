#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
const int N=550;
const int mod=998244353;
int n,m,c[N],a[N],ans,maxn;
bool fg=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string ssss;
	cin>>ssss;
	for(int i=0;i<ssss.size();i++){
		a[i+1]=(ssss[i]-'0')&1;
		if(a[i+1]==0) fg=1;
		else maxn++;
	}
	int q=0,qq=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) q++;
		if(c[i]>m) qq++;
	}
	int cntt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1 && i<=c[i]){
			cntt++;
		}
	}
	sort(c+1,c+1+n);
	int minn=c[n-m+1];
	cout<<minn<<endl;
	int mre=n-q,mre2=n-q-qq;
	if(mre<m){
		cout<<0<<endl;
		return 0;
	}
	if(fg==0){
		int ans=1,cnt=1;
		for(int i=n-m+1;i<=n;i++){
			if(c[i]<i){
				ans=(ans*(c[i]-i+(n-m+1)))%mod;
				cnt++;
			}
		}
		for(int i=n-cnt;i>=1;i--){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		if(fg=1 || q>0){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans;
		return 0;
		
	}
	if(m==1){
		ans=1;
		if(c[n]>=n){
			for(int i=1;i<=n;i++) ans=(ans*i)%mod;
			cout<<ans;
			return 0;
		}
		ans=(ans*c[n])%mod;
		for(int i=1;i<n;i++) ans=(ans*i)%mod;
		cout<<ans;
		return 0;
			

	}
}