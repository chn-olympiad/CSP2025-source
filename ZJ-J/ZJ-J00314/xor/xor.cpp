#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,kk,i,x,j,k,bj,a[N][20],fl,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>kk;
	for(i=1;i<=n;i++){
		cin>>x;
		for(j=0;j<20;j++)a[i][j]=a[i-1][j];
		for(j=0;j<20;j++)
			if((x&(1<<j))!=0)a[i][j]++;
	}
	bj=1;
	for(i=1;i<=n;i++){
		for(j=bj-1;j<i;j++){
			fl=1;
			for(k=0;k<20;k++){
				x=(a[i][k]-a[j][k])%2;
				if(x!=((kk>>k)&1))fl=0;
			}
			if(fl==1)break;
		}
		if(j!=i)ans++,bj=i+1;
	}
	cout<<ans;
	return 0;
}
//9:23 guoleyangli1--5 yuji[40,60]pts
//10:44 guoleyangli1--5 yuji60pts
//RP++