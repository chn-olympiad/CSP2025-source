#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("xor.in","r",stdin);  
	//freopen("xor.out","w",stdout);
	int n,a[500005],k,sum=0,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;i++){
			for(int x=i;i<j+1;i++){
				sum=sum^a[x];
			}
			if(sum==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
