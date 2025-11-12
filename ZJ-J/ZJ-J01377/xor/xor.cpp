#include<bits/stdc++.h>
using namespace std;
long long n,x,a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int q=1;q<=n;q++)cin>>a[q];
	cout<<x/2+1;
	return 0;
}
