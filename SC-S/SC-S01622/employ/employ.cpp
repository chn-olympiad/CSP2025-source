#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int c[114514];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=0;i<m;i++){
		ans*=(n-i);
	}
	cout<<998244353%ans;
	return 0;
}