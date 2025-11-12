#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353,N=505;
bool flag=true;
int n,m,pat=0,ans=1,a[N],t[N];
string s;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)t[a[i]]=i;
	for(int i=1;i<=n;i++)if(!t[i])t[i]=t[i-1];
	for(int i=1;i<=n;i++)if(s[i]=='0')flag=false;
	if(flag){
		for(int i=1;i<=n;i++)ans=(ans*n)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0')pat++;
		ans=ans*max(1ll,n-t[pat]-1)%mod;
	}
	cout<<ans;
	return 0;
}

