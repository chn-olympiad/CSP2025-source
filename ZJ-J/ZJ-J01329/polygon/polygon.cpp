#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,i,a[1000001],ans;
void sc(int t,int an,int ma,int kor){
	if(t>n){
		if(an>2*ma&&kor>2)ans++,ans=ans%MOD;
		return ;
	}sc(t+1,an,ma,kor);sc(t+1,an+a[t],max(ma,a[t]),kor+1);
}
 main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sc(1,0,0,0);
	cout<<ans;
	return 0;
}
