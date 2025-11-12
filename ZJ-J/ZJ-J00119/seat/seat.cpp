#include<iostream>
#include<algorithm>
using namespace std;
const int N=15;
int S[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,Ptr=0,Val;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>S[i];
	Val=S[1];
	sort(S+1,S+1+n*m);
	reverse(S+1,S+1+n*m);
	while(S[++Ptr]!=Val);
	int c=(Ptr+n-1)/n,r;
	r=c%2?(Ptr-1)%n+1:n-(Ptr-1)%n;
	cout<<c<<' '<<r;
	return 0;
}
