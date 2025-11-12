#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005],b,m,v;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b=a[i]&b;
	}
	m=b^k;
	for(int i=1;i<=n;i++){
		if(1<=i&&i<=m&&a[i]>v) v=a[i];
	}
	cout<<v;
	return 0;	
} 

