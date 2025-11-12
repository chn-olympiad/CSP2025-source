#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[50005],n,k,c=0; 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=c+a[i];
	}
	if(k==0)   cout<<n;
	if(k==1) cout<<c;
	return 0;
} 
