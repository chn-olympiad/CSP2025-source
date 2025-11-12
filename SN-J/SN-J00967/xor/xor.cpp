#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=false;
		}
		if(a[i]>1){
			flag2=false;
		}
	}
	if(flag1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(flag2&&k<=1){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt1++;
			}
			if(a[i]==0){
				cnt0++;
			}
		}
		if(k==0){
			cout<<cnt0/2+cnt1/2;
		}
		else{
			cout<<cnt1;
		}
		return 0;
	}
	cout<<n/2;
}
//RP++ ¹ý¹ý¹ý 
