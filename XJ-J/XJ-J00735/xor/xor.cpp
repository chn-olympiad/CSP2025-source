#include<bits/stdc++.h>
using namespace std;
int a[10002],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i+1;j<=n;j++){
			if(a[i]==k){
				ans++;
				continue;
			}
			else if((a[i]+a[j])==k)ans++;
		}
	}
	cout<<ans;
	return 0;
} 
