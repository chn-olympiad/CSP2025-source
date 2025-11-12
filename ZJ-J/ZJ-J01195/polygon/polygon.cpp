#include <bits/stdc++.h>
using namespace std;
int n,i,sum,a[5010],f[5010],b[5010];
void sc(int t){
	int i,k=0,s=0,ma=0;
	if(t==n+1){
		for(i=1;i<=n;i++)
			if(f[i])b[++k]=a[i];
		if(k<3)return;
		else{
			for(i=1;i<=k;i++)s+=b[i],ma=max(ma,b[i]);
			if(2*ma<s)sum++;
			return;
		}
	}
	f[t]=0;sc(t+1);f[t]=1;sc(t+1);f[t]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sc(1);
	cout<<sum%998244353;
	return 0;
}
