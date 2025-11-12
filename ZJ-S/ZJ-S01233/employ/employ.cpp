#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,c[505],maxn=LLONG_MIN;
char s[505];
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxn=max(maxn,c[i]);
	}
	if(m==1){
		ll ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	if(!flag){
		if(maxn<n-1)cout<<0;
		else{
			
		}
	}
	return 0;
}

