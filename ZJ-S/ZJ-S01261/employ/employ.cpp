#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
int n,m,a[505],p[505],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,iota(p+1,p+n+1,1);
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<11){
		do{
			int cnt=0;
			for(int i=1;i<=n;++i)if(cnt>=a[p[i]]||s[i-1]=='0')++cnt;
			ans+=(cnt<=n-m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}else cout<<0;
	return 0;
}//I love whk.
