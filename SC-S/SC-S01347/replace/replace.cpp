#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 998244353
using namespace std;
const int maxn=550;
int n,m,a[maxn],cnt=0,ans=1,ans1=0;
string s;
signed main(){
	freopen("repalce","r",stdin);
	freopen("repalce.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int p=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) p--;
	}
	for(int i=0;i<n;i++) if(s[i]=='1') cnt++;
	if(cnt==s.size()){
		for(int i=1;i<=p;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans%mod<<endl;
	}
	return 0;
}