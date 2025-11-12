#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&a[i]==k){
				ans++;
			}else{
				int sum=a[i];
				for(int w=i+1;w<=j;w++){
					sum+=(sum^a[w]);
				}
				if(sum==k){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
