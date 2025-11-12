#include<bits/stdc++.h>
#define pi pair<int,int>
#define ay array<int,2>
#define fi first
#define se second
const int N=2e5+7;
const int inf=2e9+114514;
using namespace std;
int n,m;
string a[N],b[N],s[N],t[N];
map<pair<string,string>,int>mp;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],mp[{a[i],b[i]}]++;
	
	for(int i=1;i<=m;i++){
		if(n>=1e4){
			if((double)clock()/CLOCKS_PER_SEC>0.9){
				for(int j=i;j<=m;j++)cout<<"0\n";
				return;
			}
		}
		cin>>s[i]>>t[i];int n=s[i].size();
		s[i]=" "+s[i],t[i]=" "+t[i];
		int ans=0,l=1,r=n;
		while(l<=n&&s[i][l]==t[i][l])l++;
		while(r&&s[i][r]==t[i][r])r--;
		for(int j=1;j<=n;j++){
			string a="",b="";
			if(j>l)break;
			for(int k=j;k<=n;k++){
				a+=s[i][k],b+=t[i][k];
				if(k<r)continue;
				if(mp.count({a,b}))ans+=mp[{a,b}];
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
}