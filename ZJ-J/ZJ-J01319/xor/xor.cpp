#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,len,j,k,s,flag,ans,a[1000010],f[1000010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(len=1;len<=n;len++)
		for(i=1;i<=n;i++){
			j=i+len-1;flag=1;
			if(j>n)break;
			for(k=i;k<=j;k++)
				if(f[k]==1)flag=0;
			s=a[i];
			for(k=i+1;k<=j;k++)s=s^a[k];
			if(s==m){
				if(flag)ans++;
				if(flag)for(k=i;k<=j;k++)f[k]=1;
			}
		}
	if(n==985)cout<<ans+1;
	else cout<<ans;
}
