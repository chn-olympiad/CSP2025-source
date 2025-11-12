#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt=1,cur;
int x,y;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>cur;
	for(int i=2; i<=n*m; i++) {
		int t;
		cin>>t;
		cnt+=(t>cur);
	}
	x=cnt/n+(cnt%n!=0);
	y=cnt%n;
	if(y==0) y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<" "<<y<<endl;
	return 0;
}