#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=600;
const int MOD=998244353;
int n,m,cnt;
string s;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%MOD;
	} 
	cout<<ans;
	return 0;
}
//396199761
//807877740

