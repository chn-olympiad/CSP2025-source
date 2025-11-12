#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll maxn = 505;
ll c[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m,flag = 1,res = 1,k,i;
	string s;
	cin>>n>>m;
	k = n;
	cin>>s;
	for(i = 1;i <= n;i++){
		cin>>c[i];
		if(c[i] == 0) k--;
	}
	for(i = 1;i <= k;i++) res = (res * i) % mod;
	cout<<res;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
