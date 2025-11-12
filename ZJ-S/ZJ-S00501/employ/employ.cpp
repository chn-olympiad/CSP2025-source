#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int m,ans=0,n;
string t;
int c[510],mp[510];
void dfs(int now,string s){
	if(now==n){
		int cnow=0,res=0;
		for(int i=0;i<n;i++){
			int a=s[i]-'0';
			if(t[i]=='1'&&c[a]>cnow)res++;
			else cnow++;
		}
		if(res>=m)ans++;
		if(ans==mod)ans=0;
	}
	for(int i=1;i<=n;i++){
		if(!mp[i]){
			mp[i]=1;
			string ss=s;
			ss+=(i+'0');
			dfs(now+1,ss);
			mp[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,"");
	cout<<ans;
}
