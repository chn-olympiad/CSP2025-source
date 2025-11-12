#include<bits/stdc++.h>
#define endl "\n"
#define mod 998244353
#define int long long
using namespace std;
int n,a[5010],mx,ans;
bool vis[5010];
void dg(int e,int step,int sum,int mxx,int st){
	if(step==e){
		if(sum>(mxx*2)){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=st;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dg(e,step+1,sum+a[i],max(mxx,a[i]),i+1);
		vis[i]=0;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		int x,y,z;
		cin>>x>>y>>z;
		if(((x+y)>z)&&((x+z)>y)&&((y+z)>x))cout<<"1"<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(mx==1){
		int cn=1,sum=6;
		for(int i=1;i<=n;i++)cn*=i;
		sum=sum*cn/(n-1)/(n-2)/n;
		ans+=cn/sum;
		ans%=mod;
		for(int i=4;i<=n;i++){
			sum/=(n-i+1);
			sum*=i;
			ans+=cn/sum;
			ans%=mod;
		}
		cout<<ans%mod<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++)
		dg(i,0,0,0,1);
	cout<<ans%mod<<endl;
	return 0;
}
