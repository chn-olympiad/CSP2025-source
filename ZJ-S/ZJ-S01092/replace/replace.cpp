#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define eb emplace_back
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=2e5+20,M=5e6+20;
const ll INF=1ll<<60,mod=998244353;
int n,q;
string s[N][3],t[3];
string cut(string tt,int l,int r){
	string tp="";
	for(int i=l;i<=r;i++) tp+=tt[i];
	return tp;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[1]>>t[2];
		int ans=0,len=t[1].size();
		for(int i=1;i<=n;i++){
			for(int j=0;j<len-s[i][1].size()+1;j++){
				if(cut(t[1],j,j+s[i][1].size()-1)!=s[i][1]) continue;
				if(cut(t[1],0,j-1)+s[i][2]+cut(t[1],j+s[i][1].size(),len-1)==t[2]) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

