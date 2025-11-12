#include<bits/stdc++.h>
using namespace std;
long long arr[500005][500005]={};
long long brr[500005]={};
long long yhh(long long l,long long r){
	long long ans=brr[l];
	for(int i=l+1;i<=r;i++){
		ans=ans^brr[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>brr[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			arr[i][j]=yhh(i,j);
		}
	}
	long long big=-1;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(arr[i][j]==k){
				big=max(big,j-i+1);
			}
		}
	}
	cout<<big;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
