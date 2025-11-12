#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int x,y;
	for(int i=1;i<=n;i++){
		x*=i;
	}
	for(int i=1;i<=m;i++){
		y*=i;
	}
	cout<<n/m%998244353;
	return 0;
}
