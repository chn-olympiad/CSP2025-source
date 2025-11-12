#include<bits/stdc++.h>
using namespace std;
int arr[500005]={};
int brr[500005]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	if(k==0&&n<=2){
		if(n<=1) cout<<0;
		else if(n==2) cout<<1;
		return 0;
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==k){
			sum++;
			brr[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		long long ans=arr[i];
		for(int j=i+1;j<=n;j++){
			ans=ans^arr[j];
			if(ans==k){
				for(int z=i;z<=j;z++){
					if(brr[z]!=0){
						continue;				
					}
				}
				for(int z=i;z<=j;z++){
					brr[z]=i;
				}
				sum++;
			} 
		}
	}
	for(int i=1;i<=n;i++){
		if(brr[i]==i){
			sum--;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
