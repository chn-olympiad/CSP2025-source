#include<bits/stdc++.h>
using namespace std;
long long n,k,l=1,r,ans,cnt,arr[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>arr[i];
	while(r<n){
		r++;
		ans=ans xor arr[r];
		if(ans==k){
			cnt++;
			l=r+1;
			ans=0;
		}
	}
	cout<<cnt;
	return 0;
}
