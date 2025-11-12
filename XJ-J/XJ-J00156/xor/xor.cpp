#include<bits/stdc++.h>
using namespace std;
int n,k,cnt0,cnt1;
int a[500005],y[500005];
int e[500005][10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0||k==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=2) break;
			if(a[i]==0) cnt0++;
			if(a[i]==1&&a[i+1]==1){
				cnt0++;
				i+=2;
			}
		}
		cout<<cnt0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=1,ls=a[i];
		while(ls!=0){
			e[i][j]=ls%2;
			ls/2;
		}
	}
	cout<<n;
	return 0;
}
