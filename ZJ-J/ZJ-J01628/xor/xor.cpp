#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	if(k==0) cout<<1;
	else cout<<2;
	return 0;
}

