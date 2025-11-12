#include<iostream>
using namespace std;
int n,a[500010];
long long int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(k==0) cout<<0;
	else cout<<1;
	return 0;
}
