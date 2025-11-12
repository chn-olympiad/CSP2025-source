#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[505],ans,b[505];
string s;
void solve(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=i;
	do{
		int c1=0,c2=0;
		for(int i=1;i<=n;i++){
			if(c2>=a[b[i]]) continue;
			if(s[i-1]=='1') c1++;
			else c2++;
		}
		if(c1>=m) ans++;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
