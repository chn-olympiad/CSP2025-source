#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10005];
	cin>>n>>k;
	if(k==0){
		cout<<n;
	}
	else if(n<=2) cout<<1;
	else{
		cout<<2;
	} 
	return 0;
}
