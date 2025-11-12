#include <bits/stdc++.h>
using namespace std;
long long arr[10000005];
long long crr[10000005];
struct xx{
	long long l,r,z;
}brr[10000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	int len=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n-i+1;j++){
		    if(i==1){                                                                               
		    	brr[++len].l=j;
				brr[len].r=j+i-1;
				brr[len].z=arr[j];
			} 
		    long long x=arr[j]^arr[j+1];
	    	for(long long k=j+2;k<=j+i-1;k++){ 
	    		x^=arr[k];
			}
			brr[++len].l=j;
			brr[len].r=j+i-1;
			brr[len].z=x;
		}
	}
	long long ans=0;
	for(long long i=1;i<=len;i++){
		if(brr[i].z==k){
			long long bj=0;
			for(long long j=brr[i].l;j<=brr[i].r;j++){
				if(crr[j]==1){
					bj=1;
					break;
				}
			}
			if(bj==0){
				ans++;
				for(long long k=brr[i].l;k<=brr[i].r;k++){
					crr[k]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
