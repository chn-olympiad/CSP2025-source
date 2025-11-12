#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	cin>>n;
	long long k;
	cin>>k;
	long long a[n+1];
	long long b[n+1];
	b[0]=0;
	for(long long i=1;i<n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	long long count=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(b[j]-b[i-1]==k){
				count++;
			}
		}
	}
	
	cout<<count<<endl;
	
	return 0;
} 
