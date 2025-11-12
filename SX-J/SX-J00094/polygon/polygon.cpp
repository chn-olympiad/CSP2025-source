#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
string s;
ll a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<a[1]+a[2]+a[3];
	return 0;
}