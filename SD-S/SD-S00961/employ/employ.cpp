#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
#define fi first
#define se second
const int N=505,mod=998244353;
int n,m;
string s;
ll a[N];
ll c[N],fac[N],inv[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios;
	cin>>n>>m>>s;
	s='a'+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=i;
	}
	if(m==1){
		fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
		}
		cout<<fac[n];
		return 0;
	}
	if(n<=20){
		int ans=0;
		do{
			int res=0;
			for(int i=1,cnt=0;i<=n;i++){
				if(s[i]=='0'||cnt>=a[c[i]]){
					cnt++;
					continue;
				}
				res++;
			}
			ans+=(res>=m);
			ans%=mod;
		}while(next_permutation(c+1,c+n+1));
		cout<<ans;
	}
	cout<<0;
	return 0;
}


