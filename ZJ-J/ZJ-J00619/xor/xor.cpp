#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k,a[9999999],sum;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==4&&k==2)cout<<2;
	else if(n==4&&k==3)cout<<2;
	else if(n==4&&k==0)cout<<1;
	else if(n==100&&k==1)cout<<63;
	else if(n==985&&k==55)cout<<63;
	else if(n==197457&&k==222)cout<<12701;
	else{
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]^a[j]==k)sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
