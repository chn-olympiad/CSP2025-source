#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,l[5001],ans,p[5001];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	sort(l+1,l+1+n);
	for(int i=0;i<1<<n;i++){
		int mx=0,cnt=0,sum=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j)){
				cnt++;
				sum+=l[n-j];
				if(mx==0)
					mx=l[n-j];
			}
		if(cnt>=3&&sum>mx*2)
			ans++;
	}
	cout<<ans;
	return 0;
}

