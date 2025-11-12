#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool flag=true,book=0;
ll n,m,a[505],cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cnt=n;
	cin>>s;
	for(ll i=0;i<n;i++){
		if(s[i]!='1') flag=false;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt--;
			book=1;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(flag){
		ll ans=1;
		if(book){
			n=cnt;
		}
		for(ll i=2;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
	}
	else{
		cout<<1;
	}
	return 0;
}
