#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+7;
int n,k,x[N][N],a[N],maxn,sum;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		int b=0,c=0;
		for(int r=l;r<=n;r++){
			for(int i=l;i<=r;i++){
				x[l][r]|=a[i];
			}
			if(x[l][r]==k and (r>b or c<l)){
				sum++;
			}
		}
		maxn=max(maxn,sum);
		sum=0;
	}
	cout<<maxn;
	return 0;
}
