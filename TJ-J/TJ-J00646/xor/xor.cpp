#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	int x=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k&&i>x){
				ans++;
				x=j;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//rp++
