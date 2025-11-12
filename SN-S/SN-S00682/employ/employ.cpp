#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod=998244353;
const int N=510;

int c[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1,cnt=0;cin>>n>>m;
	string s;cin>>s;bool vis1=true,vis2=false;
	for(int i=0;i<s.size();i++) if(s[i]!=1) vis1=false;
	if(vis1==false&&n==m) {cout<<0;return 0;}
	for(int i=1;i<=n;i++) {cin>>c[i];if(c[i]==0) cnt++,vis2=true;}
	if(vis2==true&&n==m) {cout<<0;return 0;}
	if(n-cnt<m) {cout<<0;return 0;}
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
