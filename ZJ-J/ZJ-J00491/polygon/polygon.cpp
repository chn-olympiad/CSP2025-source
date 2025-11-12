#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010];//xuanjige dijige
int cnt;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];

	for(int len=3;len<=n;len++){
		cnt+=n-len+1;
	}
	cout<<cnt;
	return 0;
}
