#include<bits/stdc++.h>
using namespace std;
int n,i,a[1000001],f[1000001],ans;
void sc(int t,int ma,int sum,int cs){
	if(t>n){
		if(sum>2*ma&&cs>=3) ans=(ans+1)%998244353;
		return ;
	}
	sc(t+1,ma,sum,cs);
	sc(t+1,a[t],sum+a[t],cs+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	sc(1,0,0,0);
	cout<<ans;
	return 0;
}

