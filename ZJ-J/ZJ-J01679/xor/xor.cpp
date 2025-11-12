#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,ans;
int a[maxn];
int sum[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int minn=0;
	for(int i=1;i<=n;i++){
		for(int j=minn;j<i;j++){
			if((sum[i]^k)==sum[j]){
				minn=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}