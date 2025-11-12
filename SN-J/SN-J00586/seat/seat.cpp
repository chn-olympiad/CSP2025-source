#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int op,num=1;
	cin>>op;
	for(int i=1;i<=n*m-1;i++){
		int t;
		cin>>t;
		num+=(t>op);
	}
	cout<<(num-1)/n+1<<' '<<(((num-1)%(2*n)+1)<=n?((num-1)%(2*n)+1):2*n-((num-1)%(2*n)+1)+1);
	return 0;
}
