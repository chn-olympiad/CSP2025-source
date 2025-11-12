#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,s;int a[10010];
short f[10010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=1<<n;i++){
		f[1]++;
		int j=1,s1=0,s2=0;
		while(f[j]==2)f[j]=0,j++,f[j]++;
		for(int k=1;k<=n;k++){
			if(f[k])s1+=a[k],s2=max(s2,a[k]);
		}
		if(s1>2*s2)s=(s+1)%MOD;
	}
	cout<<s<<"\n";
	return 0;
}
