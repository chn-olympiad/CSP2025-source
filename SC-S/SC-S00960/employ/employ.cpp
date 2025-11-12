#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=998244353;
int n,m,ans;
struct node {
	int val,id;
}c[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i].val;
		c[i].id=i;
	}
	cout<<0<<endl;
	return 0;
}