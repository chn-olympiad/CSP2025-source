#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,ans=1; cin>>n>>m;
	string s; cin>>s;
	for(int i=0;i<n;i++){
		int c; cin>>c;
		cnt+=(c?c:0);
	}
	if(cnt<m) cout<<0;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%md;
	}
	cout<<ans%md;
	return 0;
}