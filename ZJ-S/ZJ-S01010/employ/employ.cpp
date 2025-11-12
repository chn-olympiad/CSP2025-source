#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,mod=998244353;
int n,m,a[N],p[N],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) p[i]=i;
	sort(a+1,a+1+n);
	do{
		int cc=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'||cc>=a[p[i]]) ++cc;
			if(cc>n-m) break;
		}
		if(cc<=n-m) ++ans;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<'\n';
	return 0;
}
