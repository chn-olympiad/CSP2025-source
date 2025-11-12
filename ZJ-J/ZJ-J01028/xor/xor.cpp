#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long ans[500010];
int ans1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans1++;
	}
	int l=1;
	for(int r=1;r<=n;r++){
		if(l==r){
			ans[r]=a[r] 
			if(ans[r]==k)l=r+1;
			continue;
		}
		ans[r]=a[r]^ans[r-1];
		if(ans[r]==k)l=r+1;
	}
	int ans2=0;
	for(int i=1;i<=n;i++){
		if(ans[i]==k)ans2++;
	}
	cout<<max(ans1,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
