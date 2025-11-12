#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
long long xsum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	xsum[0] = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		xsum[i] = xsum[i-1] xor a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(xsum[i-1] xor xsum[j] == k){
				ans = max(ans,j-i);
			}
		}
	}
	cout<<ans;
	return 0;
}
