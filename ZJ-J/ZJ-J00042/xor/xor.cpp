#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c0=0,c1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) c1++;
		else c0++;
	}
	if(k==1) cout<<c1;
	else if(k!=0) cout<<n+c1+c0;
	else{
		for(int i=2;i<=n;i++){
			if(a[i-1]==a[i]&&a[i]==1){
				c0++;
				i++;
			}
		}
		cout<<c0;
	}
	return 0;
}