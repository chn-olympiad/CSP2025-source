#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],yh[500005],l=1,r=2,s=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yh[i]=yh[i-1]^a[i];
	}
	while(1){		
		if(r>n){
			break;
		}
		if(yh[r]^yh[l]==k){
			s++;
			l=r+1;
			r=l+1;
		}
		else{
			r++;
		}
	}
	cout<<s<<" "<<l<<" "<<r;
	return 0;
}
