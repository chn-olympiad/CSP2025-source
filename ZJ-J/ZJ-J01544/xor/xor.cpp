#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin>>n>>k;
	vector<int> a(n);
	long long z=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		long long s=0;
		for(long long j=i;j<n;j++){	
			s+=a[i]&a[j];
			if(s==k){
				z=max(s,z);
			}
			
		} 
	}
	cout<<z;
	return 0;
}