#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int n,m,k,a,b,c,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	return 0;
}