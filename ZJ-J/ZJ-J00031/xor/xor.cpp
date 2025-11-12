#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N=5e5+10;

ll n,k,ans,a[N],sum[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
 	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((sum[j]^sum[i-1])==k)
				ans++;
	if(ans%2==0)
		cout<<ans/2;
	else	
		cout<<floor(ans/2)+1;
	return 0;
}
