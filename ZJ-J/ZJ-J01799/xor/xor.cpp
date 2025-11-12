#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long k,a[N],sum[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int d=1;
	for(int i=1;i<=n;i++){
		for(int j=d;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				ans++;
				d=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}