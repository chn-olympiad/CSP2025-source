#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long l,r;
long long cnt=0;
long long a[500010];
long long s(long long l,long long r){
	long long sum=0;
	for(int i=l;i<=r;i++){
		sum= a[i] xor sum;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	l=1;
	r=1;
	while(l<=n){
		long long lin=s(l,r);
		if(lin>k) {
			l++;
			r=l;
		}
		else if(lin==k){
			cnt++;
			l=r+1;
			r=l;
		}else r++;
	}
	cout<<cnt;
	return 0;
} 
