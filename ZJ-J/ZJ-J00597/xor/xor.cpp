#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,i,j,t;
long long a[N];
long long find(long long n,long long k,long long a[]){
	long long result=0,sum=0;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			for(t=i;t<=j;t++){
				sum^=a[t];
			}
			if(sum==k){
				result++;
				i=t;
				sum=0;
				continue;
			}
		}
	}
	return result;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];		
	}
	cout<<find(n,k,a);
	return 0;
}

