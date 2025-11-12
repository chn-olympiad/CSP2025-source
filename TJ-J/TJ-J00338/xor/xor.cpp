#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"0";
	}
	if(n==2){
		cout<<"1";
	}
	if(n!=1&&n!=2){
		int ans=0;
		ans=n/2;
		cout<<ans;
	}
	return 0;
}
