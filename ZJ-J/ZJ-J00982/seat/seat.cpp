#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,cnt=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>s)cnt++;
	}
	int l=cnt/n;
	if(l%2==0)cout<<l+1<<" "<<cnt%n+1;
	else cout<<l+1<<" "<<n-cnt%n;
}
