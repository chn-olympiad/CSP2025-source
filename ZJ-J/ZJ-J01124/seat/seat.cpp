#include<bits/stdc++.h>
using namespace std;
long long n,m,t,xx,ii,s=1,p;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m-1;
	cin>>p;
	while(t--) {
		cin>>xx;
		if(xx>p)
			s++;
	}
	if((s+n-1)/n%2)
		cout<<(s+n-1)/n<<" "<<s-(s-1)/n*n;
	else cout<<(s+n-1)/n<<" "<<n-(s-(s-1)/n*n)+1;
	return 0;
}
