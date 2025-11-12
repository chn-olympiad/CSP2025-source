#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],j=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum=sum xor a[i];
		if(sum==k){
			ans++;
			sum=0;
			continue;
		}
		else if(sum>k){
			j++;
			i=j;
			sum=0;
			continue;
		}
	}
	cout<<ans;
	return 0;
}

