#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
const int N=520;
int n,m,c[N];
string s;
bool flag;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<s.size();i++){
		if(!(s[i]-'0')) flag=1;
	}
	if(!flag){
		int mul=1;
		for(int i=1;i<=n;i++){
			mul=(mul*i)%MOD;
		}
		cout<<mul;
	}
	else cout<<0;
	return 0;
}
