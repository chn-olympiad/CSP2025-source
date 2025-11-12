#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=5e2+10,M=1+10,mod=998244353;
const double eps=1e-1;
const long double pi=acos(-1);
int n,m,c[N],p[N],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]])cnt++;
			else if(s[i-1]=='0')cnt++;
		}
		if(n-cnt>=m)ans=(ans+1)%mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}
