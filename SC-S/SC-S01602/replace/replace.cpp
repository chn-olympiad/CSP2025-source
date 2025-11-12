#include<bits/stdc++.h>
#define endl '\n'
#define ri register int
#define int long long
#define fixedset(a) fixed << setprecision(a)
#define pii pair<int,int>
#define mp make_pair
#define ls(x) x<<1
#define rs(x) x<<1|1
#define eps 1e-7
#define inf 2114514
#define mf 5011
#define sf 1011
#define MOD 114514
#define mod(x) (x+MOD)%MOD;
using namespace std;
int n,m;
map<string,string> rcd;
void solve(){
	int ans=0;
	string a,b; cin >> a >> b;
	if(a.length()!=b.length()){
		cout << "0" << endl;
		return ;
	}
	int n=a.length();
	a=' '+a; b=' '+b;
	for(ri i=1;i<=n;i++) for(ri j=i;j<=n;j++){
		int len1=i-1,len2=j-i+1,len3=n-j;
		if(!rcd.count(a.substr(i,len2))) continue;
		string chk="";
		if(len1) chk=a.substr(1,len1);
		chk=chk+rcd[a.substr(i,len2)];
		if(len2) chk=chk+a.substr(j+1,len3);
		chk=' '+chk;
		if(chk==b) ans++;
	}
	
	cout << ans << endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for(ri i=1;i<=n;i++){
		string a,b; cin >> a >> b;
		rcd[a]=b;
	}
	for(ri i=1;i<=m;i++) solve();
	return 0;
}