#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=505,MOD=998244353;
string s;
ll f[N][N][2],a[N],cnt[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll n,m;
	cin>>n>>m>>s;
	vector<int>b[505];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(s[i-1]=='1'&&cnt[i]<a[i]) b[j].push_back(a[i]); 
		}
	}
	for(int i=0;i<s.size();i++) cnt[i]=cnt[i-1]+s[i]-'0';
	if(cnt[s.size()-1]==s.size()) {
		ll sum=1;
		for(int i=1;i<=n;i++)sum*=i,sum%=MOD;
		cout<<sum;
	}else{
		ll sum=1;
		for(int i=1;i<=n;i++)sum*=b[i].size(),sum%=MOD;
		cout<<sum;
	}	
	return 0;
}