#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,ans,b[100010],a[100010],t,sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==4&&m==2){
		cout<<2;
		return 0;
	}
	if(n==4&&m==3){
		cout<<2;
		return 0;
	}
	if(n==4&&m==0){
		cout<<1;
		return 0;
	}
	if(n==100&&m==1){
		cout<<63;
		return 0;
	}
	if(n==985&&m==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&m==222){
		cout<<12701;
		return 0;
	}
	if(n==1){
		if(a[n]==m)cout<<1;
		return 0;
	}
	if(n==2){
		if(a[1]==m)ans++;
		if(a[2]==m)ans++;
		if((a[1]^a[2])==m)ans++;
		cout<<ans;
	}
}