#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5005],ans,num,shang,xia;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(a[n]==1){
		ans=0;
		for(int i=3;i<=n;i++){
			shang=xia=1;
			for(int j=n;j>n-i;j--){
				shang*=j;
				shang%=MOD;
			}
			for(int j=1;j<=i;j++){
				xia*=j;
				xia%=MOD;
			}
			ans+=(shang/xia);
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
