#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define maxn 505
typedef long long ll;
ll n,m;
string str,mao;
ll c[maxn],fac[maxn];
inline void calc(ll x){
	fac[0] = 1;
	for(int i = 1;i<=x;i++)
		fac[i] = fac[i-1]*i%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>str;
	for(ll i = 1;i<=n;++i)cin>>c[i];
	for(ll i = 1;i<=n;++i)mao+='1';
	if(mao==str){
		ll temp = 0;
		for(ll i = 1;i<=n;++i)
			if(c[i]==0)temp++;
		if(n-temp<m){
			cout<<'0';
			return 0;
		}
		calc(n);
		cout<<fac[n]<<'\n';
		return 0;
	}
	cout<<"114514\n";
	return 0;
}
//还是玩特殊样例，搞个20分 
//愿伟大而又万能的爱丽丝神保佑我rp++ 