#include<bits/stdc++.h>

using namespace std;
int n,m,a,sum=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>a)sum++;
	}
	int t=(sum-1)/m+1;
	if(t%2==1)cout<<t<<' '<<sum-m*(t-1);
	else cout<<t<<' '<<m*t-sum+1;
	return 0;
}
