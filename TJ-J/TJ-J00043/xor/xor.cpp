#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],sum[maxn],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		//cout<<sum[i]<<' ';
	}
	for(int i=1;i<=n;){
		for(int j=i;j<=n;j++){
			if(sum[j]^sum[i-1]==k){
				ans++;
				//cout<<(sum[i-1]^sum[j]);
		        i=j;
		        //cout<<i;
				break;
			}
		}
		i++;
	}
	cout<<n/2;
	return 0;
}

