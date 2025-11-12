#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n,m,cnt,ans;
string s;
struct per{
	int c,id;
	bool operator<(const per&o)const{return id<o.id;}
}a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i = 0;i<s.size();i++) if(s[i]=='1') cnt++;
	for(int i = 1;i<=n;i++) cin>>a[i].c,a[i].id = i;
	if(cnt<m) return cout<<0,0;
	do{
		int tot=0,sum=0;
		for(int i = 1;i<=n;i++){
			if(tot<a[i].c&&s[i-1]=='1') sum++;
			else tot++;
		}
		if(sum>=m) ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans%mod;
	return 0;
}
