#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const LL Mod=998244353;
LL n,m,ans=1,c[505],tot;
vector<int> G;
string s;
int main()
{
	Fcin;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(LL i=1;i<=n;++i) cin>>c[i];
	for(LL i=1;i<=n;++i)
	{
		if(tot>=c[i]) {tot++;continue;}
		G.push_back(1);
	}
	int len=G.size();
	for(LL i=2;i<=len;++i)
		ans=(ans*(i%Mod))%Mod;
	cout<<ans;
	return 0;
}

