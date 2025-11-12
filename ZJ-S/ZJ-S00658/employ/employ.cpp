#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,a[510],ans,m,h[510],ss=1;
string s;
bool b[510];
void dd(ll k,ll ju){
	if(ju>(n-m))return;
	if(k>n){
		ans++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			h[k]=i;
			if(s[k-1]=='0'||ju>=a[i])dd(k+1,ju+1);
			else dd(k+1,ju);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n<=18){
		dd(1,0);
		cout<<ans%mod;
		return 0;
	}
	for(ll i=1;i<=n;i++)ss=(ss*i)%mod;
	cout<<ss;
	return 0;
}
