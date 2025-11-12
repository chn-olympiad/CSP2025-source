#include<bits/stdc++.h>
using namespace std;//a[l] ~ a[r] de yi huo he = b[r] yi huo b[l-1]
long long n,k,a[500015],b[500015],l,r,mid;
bool check(long long x){
	long long cnt=0;
	for(int p=1;p<=n;p++){
		cnt=0;
		for(int i=p;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((b[j]^b[i-1])==k){
					cnt++;
					if(cnt==x)return true;
					i=j;
					break;
				}
			}
		}
	}
	
	if(cnt==x)return true;
	return false;
}

int main()
{
	freopen("xor.in","r",stdin);
  	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	l=0;
	r=n;
//	for(int i=n;i>=0;i--){
//		if(check(i))cout<<i;
//		return 0;
//	}
//	cout<<0;
	while(l+1!=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	
	return 0;
}

