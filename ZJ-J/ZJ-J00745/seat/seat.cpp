#include <bits/stdc++.h>
using namespace std;
int n,m,a[111],pm=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) continue;
		if(a[i]>a[1]) pm++;
	}
	cout<<pm/n+1<<" ";
	if((pm/n)%2==0) cout<<pm%n+1;
	else cout<<n-pm%n;
	return 0;
}
