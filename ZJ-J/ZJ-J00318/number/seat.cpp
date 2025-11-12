#include<bits/stdc++.h>
using namespace std;
long long n,m,l,x,y;
long long main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m>>y;
	for(int i=n*m-1;i;i--){
		cin>>x;
		l+=x>y;
	}
	cout<<l/n<<" "<<min(l%(2*n),2*n-l%(2*n));
	return 0;
}
