// SN-S00253  张笑语  西安高新第一中学
#include<bits/stdc++.h>
#define int long long
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
namespace asbt{
const int maxn=505,mod=998244353;
int n,m,fac[maxn],a[maxn],b[maxn];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*1ll*i%mod;
	}
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]){
			cout<<0;
			return 0;
		}
	}
	cout<<fac[n];
	return 0;
}
}
signed main(){return asbt::main();}

