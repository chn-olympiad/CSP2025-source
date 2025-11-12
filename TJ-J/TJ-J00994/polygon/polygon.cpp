#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int arr[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int q=0;
			for(int z=i;z<=j;z++){
				q+=arr[z];
				if(q>arr[j]*2){
					ans++;
				}
			}
			int k=q-2*arr[j];
			if(k>0){
				for(int u=i+1;u<=j-1;u++){
					if(arr[u]<k){
						ans++;
					}
					if(k<=0)break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
