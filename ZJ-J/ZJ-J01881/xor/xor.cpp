#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5]={};
	bool flag1=true,flag2=true;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=false;
		else cnt1++;
		if(a[i]!=0)flag2=false;
		else cnt2++;
	}
	if(flag1){
		if(k==0){
			if(n%2==0)cout<<n/2;
		}
	}
	else if(flag2){
		if(k==0){
			cout<<n;
		}
	}
	else{
		if(k==0){
			cout<<cnt1/2+cnt2;
		}
		if(k==1){
			cout<<min(cnt1,cnt2);
		}
	}
	return 0;
}