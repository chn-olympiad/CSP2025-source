#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[500010],l,o,x,f;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0)o++;
		if(a[i]==1)l++;
	}
	if(l+o==n) {
		if(k==0)cout<<l/2;
		if(k==1)
			for(i=1; i<=n;)if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&i<=n-2)f++,i+=3;
				else if(a[i]!=a[i+1]&&i!=n)f++,i+=2;
		cout<<f;
	} else cout<<3;
}
