#include<bits/stdc++.h>
#define N 5005
#define mod 998244353
using namespace std;
void pls(int &a,int b){a=(a+b>=mod?a+b-mod:a+b);}
int n,a[N],g[N],f[N],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1),f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++)	pls(ans,f[j]);
		for(int j=0;j<=5001;j++)	g[j]=f[j];
		for(int j=0;j<=5001;j++)	pls(f[min(j+a[i],5001)],g[j]);
	}
	cout<<ans;
	return 0;
}
