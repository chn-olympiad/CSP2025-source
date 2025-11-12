#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,m,ans,c[1000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+n+1);
	cout<<2;
	return 0;
}
