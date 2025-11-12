#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c[N];
#define int long long
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=1,sum=0,a=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		if(c[i]==0) {
			sum++;
		}
	}
	for(int i=2; i<=n-sum-a; i++) {
		cnt=cnt*i%998244353;
	}
	cout<<cnt;
	return 0;
}
