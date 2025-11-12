#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ansk1=0,ansk0=0;
	cin>>n>>k;
	bool flag=true,flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ansk1++;
		if(a[i]==0) ansk0++;
		if(a[i]!=k) flag=false;
		if(a[i]!=1) flag2=false;
	}
	if(k==0){
		if(flag2){
			cout<<n/2;
			return 0;
		}else{
			cout<<ansk1/2+ansk0;
			return 0;
		}
	}
	if(k==1){
		cout<<2*min(ansk1/2,ansk0/2);
		return 0;
	}
	if(flag){
		cout<<n;
		return 0;
    }
    cout<<n;
	return 0;
}
