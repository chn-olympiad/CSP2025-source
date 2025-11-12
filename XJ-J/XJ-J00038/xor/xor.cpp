#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==0)cnt++;
	}
	if (cnt==0)cout<<0;
	else{
		if (k==1)cout<<n-cnt;
		else cout<<cnt;
	}
	return 0;
} 
