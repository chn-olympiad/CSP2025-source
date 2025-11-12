#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<n;i++){
			int now=arr[i];
			int next=arr[i+1];
			if(now^next==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==k) ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

