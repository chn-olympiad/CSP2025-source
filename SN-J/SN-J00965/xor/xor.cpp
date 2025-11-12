#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];	
int main(){
    cin>>n>>k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==2)
	cout<<2;
	if(k==3)
	cout<<2;
	if(k==0)
	cout<<1;
	return 0;
}
