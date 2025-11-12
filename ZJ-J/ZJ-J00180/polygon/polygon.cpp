#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],f[50050][105],s,ma;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	s=0;ma=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	sizeof(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=s;j>=a[i];j--)
			for(long long k=0;k<=ma;k++){
				if(j>2*max(k,a[i])) f[j][max(k,a[i])]+=f[j-a[i]][k]+f[j-a[i]][a[i]];
				if(j>2*min(k,a[i])){
					f[j][min(k,a[i])]+=f[j-a[i]][min(k,a[i])];
					if(k==a[i]) f[j][min(k,a[i])]+=f[j-a[i]][k];
				}
				f[j][max(k,a[i])]%=998244353;
				f[j][min(k,a[i])]%=998244353;
			}
	cout<<f[s][ma]/4;
	return 0;
}
