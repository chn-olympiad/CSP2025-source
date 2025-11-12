//hhz RP++ SCORE++ pts++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e3+5;
int n;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		int sum=0,mx=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if(sum>(2*mx)){
			cout<<1;
			return 0;
		}
	}
	else if(n==4){
		int sum=0,mx=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if(sum>(2*mx)){
			ans++;
		}
		for(int i=1;i<=2;i++){
			if((a[i]+a[i+1]+a[i+2])>(2*max(max(a[i],a[i+1]),max(a[i+1],a[i+2])))){
				ans++;
			}
		}
		int y=a[1]+a[3]+a[4];
		if(y>(2*max(max(a[1],a[3]),max(a[1],a[4])))){
			ans++;
		}
		int x=a[1]+a[2]+a[4];
		if(x>(2*max(max(a[1],a[2]),max(a[1],a[4])))){
			ans++;
		}
		cout<<ans;
	}
	else if(n==5){
		int sum=0,mx=0,ans=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if(sum>(2*mx)){
			ans++;
		}
		for(int i=1;i<=2;i++){
			if((a[i]+a[i+1]+a[i+2]+a[i+3])>(2*max(max(a[i],a[i+1]),max(a[i+2],a[i+3])))){
				ans++;
			}
		}
		for(int i=1;i<=3;i++){
			if((a[i]+a[i+1]+a[i+2])>(2*max(max(a[i],a[i+1]),max(a[i+1],a[i+2])))){
				ans++;
			}
		}
		int y=a[1]+a[3]+a[4];
		if(y>(2*max(max(a[1],a[3]),max(a[1],a[4])))){
			ans++;
		}
		int g=a[1]+a[3]+a[5];
		if(g>(2*max(max(a[1],a[3]),max(a[1],a[5])))){
			ans++;
		}
		int h=a[1]+a[2]+a[4];
		if(h>(2*max(max(a[1],a[2]),max(a[1],a[4])))){
			ans++;
		}
		int u=a[1]+a[2]+a[5];
		if(u>(2*max(max(a[1],a[2]),max(a[1],a[5])))){
			ans++;
		}
		int v=a[2]+a[3]+a[5];
		if(v>(2*max(max(a[2],a[3]),max(a[2],a[5])))){
			ans++;
		}
		int w=a[1]+a[4]+a[5];
		if(w>(2*max(max(a[1],a[4]),max(a[1],a[5])))){
			ans++;
		}
		int qw=a[2]+a[4]+a[5];
		if(qw>(2*max(max(a[2],a[4]),max(a[2],a[5])))){
			ans++;
		}
		//4
		int we=a[1]+a[2]+a[4]+a[5];
		int mxn=max(max(a[1],a[2]),max(a[4],a[5]));
		if(we>2*mxn){
			ans++;
		}		
		int er=a[1]+a[2]+a[3]+a[5];
		int mxd=max(max(a[1],a[2]),max(a[3],a[5]));
		if(er>2*mxd){
			ans++;
		}
		int yu=a[1]+a[3]+a[4]+a[5];
		int mxf=max(max(a[1],a[3]),max(a[4],a[5]));
		if(yu>2*mxf){
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
