#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[505];
int cnt=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cnt+=(c[i]==0);
	}
	int res1=1,res2=1;
	for(int i=1;i<=n;i++) res1*=i%=mod;
	for(int i=1;i<=m;i++) res2*=i%=mod;
	cout<<res1/res2;
	return 0;
}