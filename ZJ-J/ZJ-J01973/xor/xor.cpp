#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],d[N],ans,l=INT_MAX,r;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>r;j--){
			if((d[i]^d[j-1])==k){
				ans++;
				r=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
