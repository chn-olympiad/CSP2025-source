#include<bits/stdc++.h>
using namespace std;
long long a[510000],f1[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	long long ans=0,p=0;
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long x=a[1],l=1,r=1;
	while(l<=r){
		if(x==k){
			f1[l]=1;
			if(r<n){
				r++;
				x=x^a[r];
			}
			else{
				x=x^a[l];
				l++;
			}
		}
		if(r==n){
			x=x^a[l];
			l++;
		}
		else{
			if(x<k and r<n){
				r++;
				x=x^a[r];
			}
			if(x>k){
				if(l<r){
					x=x^a[l];
					l++;
				}
				else{
					r++;
					x=x^a[r];
				}
			}
		}
	}
	for(long long i=1;i<=501000;i++){
		p+=f1[i];
		ans=max(ans,p);
	}
	printf("%lld",ans);
	return 0;
}
