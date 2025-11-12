#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,kk,i,len,j,ma,ans,t,a[1010],b[1010],f[1010][1010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i],b[i]=(b[i-1]^a[i]),ma=max(ma,a[i]);
	if(ma<=1){
		if(k==0){
			for(i=1;i<=n;i++)
				if(a[i]==0)ans++,t=0;
				else{
					if(t==0)t=1;
					else ans++,t=0;
				}
			cout<<ans;
		}
		else{
			for(i=1;i<=n;i++)ans+=(a[i]);
			cout<<ans;
		}
		return 0;
	}
	ma=0;
	for(i=1;i<=n;i++)f[i][i]=(a[i]==k),ma=max(ma,f[i][i]);
	for(len=2;len<=n;len++)
		for(i=1;(i+len-1)<=n;i++){
			j=i+len-1;
			f[i][j]=((b[j]^b[i-1])==k);
			for(kk=i;kk<j;kk++)
				f[i][j]=max(f[i][j],f[i][kk]+f[kk+1][j]);
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
			ma=max(ma,f[i][j]);
		}
	cout<<ma;
	return 0;
}
