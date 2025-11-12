#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long 
#define endl '\n'
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e4+10 , M = 1e6+10 , inf = 0x3f3f3f3f3f3f3f3f ,mod = 998244353 ;
int a[N];
signed main(){
	freopen("employ3.in","r",stdin);
//	freopen(".out","w",stdout);
	fst
	int n,m;
	string s;
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(s[1]=='1'){
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans%mod;
	} 
	else{
		int cnt=1,res=0,ans=1;
		while(s[cnt]=='0') cnt++;
		cnt--;
		for(int i=1;i<=n;i++) if(a[i]>=cnt) res++;
		for(int i=1;i<=res;i++) ans=(ans*i)%mod;
		cout<<ans%mod;
	}

	return 0;
}

//  Ren5Jie4Di4Ling5%
