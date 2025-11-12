#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,a1,cnt=0;
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>a1) cnt++; 
	}
	int y=cnt/n+1,x=cnt%n+1;
	if(y%2==0) x=n-x+1;
	cout<<y<<' '<<x<<endl;
	return 0;
}
