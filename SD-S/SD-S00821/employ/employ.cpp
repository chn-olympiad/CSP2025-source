#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define Fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define fre(k) freopen(k".in","r",stdin),freopen(k".out","w",stdout)
using namespace std;
const int N=1e5+10,P=998244353;
int n,m,a[N],p[N],ans;
string s;
signed main(){
	fre("employ");
	Fast;cin>>n>>m>>s;
	rep(i,1,n) cin>>a[i],p[i]=i;
	do{
		int cnt=0;
		rep(i,1,n) if(s[i-1]=='1'&&i-cnt-1<a[p[i]]) cnt++;
		if(cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans%P;
	return 0;
}

