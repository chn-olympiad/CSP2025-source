#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k;
int a[N],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,t=2;i<=n;i++){
			for(int j=i;j<=n;j++){
			int sum=a[i];
			for(;t<=j;t++){
				sum^=a[t];
			}
			if(sum==k){		
				ans++;
				break;
			}		
		}
	}

	cout<<ans;
	return 0;
}