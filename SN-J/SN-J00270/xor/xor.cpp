#include<bits/stdc++.h>
#define lint long long 
using namespace std;
int n,max,a[10001];
lint ans,c[5005][50005];
int main()
{
	freopen("polygon.in","r",stdin)	
	freopen("polygon.out","w",stdin)
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>max) max=a[i];
	}
	if(max == 1)
	{
		for(int i=0;i<=n;i++) c[i][0] =i;
		for(int i=1,i<+n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=(1LL*c[i-1][j]+c[i-1][j-1] % P);
			}
				cout<<i<" ";
			}
		}
	for(int i=3;i<=n;i++)ans= (ans+c[n][i])
	cout<<ans;
	return 0;
	}
	if(n<=30){
		for(int msk=1;msk<=(1<<(n+1)));{
		int p=0,mx=0;
		for(int i=1;i<=n;i++)if(msk & (1))
		if(p<3) continue;
	}
	}
	return ;
}
