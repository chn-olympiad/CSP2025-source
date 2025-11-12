#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[505],l;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;
		l+=s[i-1]-48;
	}
	if(l<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
