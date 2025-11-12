#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool ok=1;
	int s1,s2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) ok=0;
		if(a[i]==0) s1++;
		if(a[i]==1) s2++;	
	}
	if(ok&&k<=1){
		if(k==1) cout<<s2;
		else cout<<s1;
		return 0;
	}
	int l=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			l=i+1;
			continue;
		}
		int sum=a[i];
		for(int j=i-1;j>=l;j--){
			sum^=a[j];
			if(sum==k){
				ans++;
				l=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
