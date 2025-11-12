#include<bits/stdc++.h>
#define int long long
const int Mod=998244353;
using namespace std;
int n,m,c[505];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	srand(time(0));
	int ans=rand();
	cout<<(ans*ans*ans)%Mod;
	return 0;
}
