#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int order=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>k;
	for(int i=2;i<=n*m;i++){
		int t;
		cin>>t;
		if(t>k) order++;
	}
	int y=(order/n);
	int x=order%n;
	if(x) y++;
	else x=n;
	if(!(y & 1)){
		x=n+1-x;
	}
	cout<<y<<' '<<x;
	return 0;
}

