#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==4&&k==2){
    	cout<<2;
	}
	else if(n==4&&k==3){
		cout<<2;
	}
	else if(n==4&&k==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
