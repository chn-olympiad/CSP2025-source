#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,cnt=1;
	cin>>n>>m>>a;
	int s=n*m;
	for(int i=2;i<=n*m;i++){
		int t;
		cin>>t;
		if(t>a) cnt++;
	}
	int x=(int)ceil(cnt/n);
	int y=cnt%n;
	if(y==0) y+=n;
	cout<<x<<" "<<y;
	return 0;
}
