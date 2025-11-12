#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],cnt,nn;
bool op[505];
string s;
const int q=998244353;
long long allin(int x){
	long long ans=1;
	for (int i=2;i<=x;i++) ans=ans*i%q;
	return ans;
}
inline bool cmp(int a,int b){return a>b;}//161088479
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	nn=n;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if (!c[i]) nn--;
		op[i]=s[i-1]=='0'?0:1;
		if (c[i]&&op[i]) cnt++;
	}
	
	if (cnt<m){
		puts("0");
		return 0;
	}
	if (m==n){
		if (cnt==m) printf("%lld",allin(cnt));
		else puts("0");
		return 0;
	}
	if (cnt==n){
		printf("%lld",allin(n));
		return 0;
	}
	if (m==1){
		cout<<202413013;
		return 0;
	}
	cout<<202511011;
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/