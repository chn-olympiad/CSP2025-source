#include<bits/stdc++.h>
using namespace std;
int n,m,x,r,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	x=n*m;
	cin>>r;
	for(int i=2;i<=x;i++){
		int y;
		cin>>y;
		if(y>r)l++;
	}
	cout<<(l-1)/n+1<<" ";
	if((l-1)/n%2==0)cout<<(l-1)%n+1;
	else cout<<n-((l-1)%n);
	return 0;
}
