#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[510],p[510];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	int sum=0;
	do{
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			ans++;
		}
		if(ans>=m) sum++;
	}while(next_permutation(p+1,p+n+1));
	cout<<sum%mod;
	return 0;
}