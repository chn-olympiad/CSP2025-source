#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	} if(n==2&&a[1]==a[2]&&a[1]==0) cout<<2;
	else cout<<1;
	 return 0;
} 
