#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=(1<<20)+5;
int dp[N][20],n,m,a[30],c[30];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=18){
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;
			if(ch=='1')
				a[i]=1;
			else
				a[i]=0;
		}
		for(int i=1;i<=n;i++)
			cin>>c[i];
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++)
				if(i&(1<<j))
					cnt++;
			for(int j=0;j<=n;j++){//
				for(int k=1;k<=n;k++){
					if(i&(1<<k-1))
						continue;
					if(j>=c[k]||a[cnt+1]==0)
						dp[i|(1<<k-1)][j+1]+=dp[i][j];
					else
						dp[i|(1<<k-1)][j]+=dp[i][j];
					
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)
			ans+=dp[(1<<n)-1][i];
		cout<<ans<<"\n";
	}
	else{
		cout<<"0\n";
		
	}
	return 0;
}
