#include <bits/stdc++.h> 
using namespace std;
const int N = 2e5+15 , L = 1e6+15;
int nxt[L],nxt2[L],f[L];
int solve(const string &a,const string &b,const string &c,const string &d){
	int n = a.size()-1;
	int st = 0 , ed = L;
	for(int i = 2 , j = 0; i<=n ; i++){
		while(j&&a[i]!=a[j+1]) j = nxt[j];
		if(a[i]==a[j+1]) ++j;
		nxt[i] = j;
	}
	for(int i = 2 , j = 0; i<=n ; i++){
		while(j&&c[i]!=c[j+1]) j = nxt2[j];
		if(c[i]==c[j+1]) ++j;
		nxt2[i] = j;
	}
	int m = b.size()-1;
	for(int i = 1 ; i<=m ; i++) if(b[i]!=d[i]){
		if(!st) st = i;
		ed = i;
	}
	for(int i = 1 , j = 0; i<=m ; i++){
		while(j&&b[i]!=a[j+1]) j = nxt[j];
		if(b[i]==a[j+1]) ++j;
		f[i] = j;
	}
	int ret = 0;
	for(int i = 1 , j = 0 ; i<=m ; i++){
		while(j&&d[i]!=c[j+1]) j = nxt2[j];
		if(d[i]==c[j+1]) ++j;
		if(i>=ed&&i-n+1<=st&&j==n&&j==f[i]) ++ret;
//		if(i==m) cout<<"Here:"<<f[i]<<" "<<j<<"\n";
	}
	return ret;
}
int n,q;
string s[N][2],l1,l2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1 ; i<=n ; i++) cin>>s[i][0]>>s[i][1],s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
	while(q--){
		cin>>l1>>l2;
		l1 = " "+l1 , l2 = " "+l2;
		int ans = 0;
		for(int i = 1 ; i<=n ; i++) ans+=solve(s[i][0],l1,s[i][1],l2)/*,cout<<s[i][0]<<" "<<l1<<" "<<s[i][1]<<" "<<l2<<" "<<solve(s[i][0],l1,s[i][1],l2)<<" "<<ans<<"\n"*/;
		cout<<ans<<"\n";
	}
	return 0;
}
/*3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/