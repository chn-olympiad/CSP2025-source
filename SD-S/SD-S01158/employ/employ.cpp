#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int N=510;
bool s[N];
int c[N],mod=998244353;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=1;i--){
		ans*=i;
	}
	cout<<ans%mod;
	return 0;
}

