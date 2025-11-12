#include <bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
const int N=5e5+10;
int n,k,a[N],sum[N],ans;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	int t=0;
	for(int r=1;r<=n;r++){
		for(int l=t;l<r;l++){
			if((sum[l]^sum[r])==k) {
				ans++,t=r;
				break;	
			}
		}
	}cout<<ans;
   	return 0;
}

