//SN-J00966  袁浩文  西安辅轮中学
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mymax(x,y) x>y?x:y
using namespace std;
int n,k,a[500005],ans=-inf,cc,ctn,tcn;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1||a[i]==0)cc++;
		if(a[i]==1)ctn++;
	}
	if(ctn==n){
		cout<<n/2;
		return 0;
	}
	if(cc==n){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)tcn++;
			}
			cout<<tcn;
			return 0;
		}

		if(k==0){
			int cnt=0,sum=0;
			for(int j=1;j<=n;j++){
				cnt^=j;
				if(cnt==k)sum++,cnt=0;
			}
			ans=mymax(sum,ans);
			cout<<ans;
			return 0;
		} 
	}
	for(int i=1;i<=n;i++){
		int cnt=0,sum=0;
		for(int j=i;j<=n;j++){
			cnt^=j;
			if(cnt==k)sum++,cnt=0;
		}
		ans=mymax(sum,ans);
	}
	cout<<ans;
	return 0;
}
