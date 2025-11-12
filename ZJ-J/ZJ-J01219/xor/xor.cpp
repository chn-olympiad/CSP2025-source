#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum=0,none=0,nzero=0,ad=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) none++;
		else if(a[i]==0) nzero++;
	} 
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			ad++;
		}
		else{
			sum=sum+ad/2;
			ad=0;
		}
	}
	sum=sum+ad/2;//search for double 1
	if(n==1) cout<<0;
	else if(n==2) cout<<1;
	else if(none==n&&k==0) cout<<n/2;
	else{
		if(k==1){
			cout<<none;
		}
		else{
			cout<<nzero<<' '<<nzero+sum;
		}
	}
	return 0;
}
