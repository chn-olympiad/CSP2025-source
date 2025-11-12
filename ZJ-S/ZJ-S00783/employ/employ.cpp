#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,P=998244353;
int n,m,a[N];
string s;
int A(int l,int r){
	int res=1;
	for(int i=r;i>=r-l+1;i--) res=res*i%P;
	return res;
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<A(m,n);
	return 0;
}