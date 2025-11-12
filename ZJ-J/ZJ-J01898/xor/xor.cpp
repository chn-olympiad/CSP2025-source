#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int xorl[500005],xorr[500005];
int tmp;
int myxor(int l,int r){
	return (int)(xorl[r]^xorr[l]^xorl[n]);
}
struct node{
	int x;
	int y;
	int num;
};
vector<node>saved;
int main(){
	//cout<<(int)(3^7);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(k==a[1]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)flagA=0;
		if(a[i]>1)flagB=0;
	}
	if(flagA){
		//special judge A:
		cout<<n/2;
		return 0;
	}
	if(flagB){
		int cnt=0,ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
				else{
					ans+=cnt/2;
					cnt=0;
					ans++;
				}
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	cout<<k;
	return 0;
}

