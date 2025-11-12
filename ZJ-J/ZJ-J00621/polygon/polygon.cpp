#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],ans;
void dfs(int wz,long long bch,long long zdz,long long sl){
	if(sl>=3&&bch>zdz*2)ans++;
	int s=ans;
	if(wz>=n)return;
	for(int i=wz+1;i<=n;i++){
		dfs(i,bch+a[i],max(zdz,a[i]),sl+1);
	}
	b[wz]=ans-s-1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,a[1],a[1],1);
	for(int i=2;i<=n-2;i++)ans+=b[i];
	cout<<ans%998244353;
	return 0;
}