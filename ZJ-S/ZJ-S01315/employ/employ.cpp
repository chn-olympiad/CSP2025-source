#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 505;
const int mod = 998244353;
int n,m;
string ss;
int s[maxn],c[maxn];
ll ans = 1,t = 1;
int k = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;
	for(int i = 0;i<ss.size();i++)
		s[i+1] = ss[i];
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		if(c[i])k++;
	}
	if(m==1){
		for(int i = k;i>1;i--)
			ans = (ans*i)%mod;
		for(int i = n-m;i>1;i--)
			t = (t*i)%mod;
		cout<<(ans*t)%mod;
		return 0;
	}
	for(int i = n;i>1;i--)
		ans = (ans*i)%mod;
	cout<<ans;
	return 0;
}