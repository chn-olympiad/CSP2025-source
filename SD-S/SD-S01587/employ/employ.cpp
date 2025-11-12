#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int Mod=998244353;
ll n,m,ans;
ll c[N],res;
string s;
void fun(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(ll i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	res=1;
	for(ll i=2;i<m;i++)
		res=(res*i)%Mod;
	for(ll i=m;i<=n;i++)
		ans=(ans+(res*i)%Mod)%Mod,res=(res*i)%Mod;
	printf("%lld\n",ans);
	return ;
}
int main(){
	fun();
	return 0;
}

