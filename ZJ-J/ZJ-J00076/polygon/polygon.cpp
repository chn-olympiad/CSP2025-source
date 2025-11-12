#include<bits/stdc++.h>
using namespace std;	
const int N=998244353;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int a[5001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long k=1,j=n,sum=0;
	while(--n){
		k*=2;
		k++;
	}
	for(long long i=1;i<=k;i++){
		long long x=i,l=i;
		sum=0;
		int fl=1,mx,num=0;
		for(int k=1;k<=j;k++){
			if(x&1){
				if(fl==1){
					mx=a[j-k+1];
					fl=0;
				}
				sum+=a[j-k+1];
				num++;
			}		
			x=x>>1;
		}	
		
		if(sum>mx*2&num>=3){
			cout<<sum<<" "<<l<<" "<<mx<<endl;
			ans++;
			if(ans>=N)ans-=N;
		}
	}
	cout<<ans;
	return 0;
}
