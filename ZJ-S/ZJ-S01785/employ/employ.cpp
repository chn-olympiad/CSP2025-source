#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
int p,k;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	p=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p=p*i%mod;
	}cout<<p;
	return 0;
}
