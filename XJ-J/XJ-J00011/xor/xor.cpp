#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	int a[500005];
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		int he=a[i];
		if(a[i]==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			he=he^a[j];
			if(he==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		if(a[i]==0){
//			continue;
//		}
//		if(a[i]==k){
//			ans++;
//		}
//	}
	
	cout<<ans;
	return 0;
} 
