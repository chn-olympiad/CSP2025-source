#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
inline int read()
{
	int num=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') sign=(ch== '-' ? -1:1),ch=getchar();
	while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-48,ch=getchar();
	return sign>0 ? num:-num;
}
int t,n;
int a[100008],b[100008],c[100008],ans=0;
int dp[208][108][108],f[100004][50004];
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--)
    {
        n=read();
        ans=0;
        if(n<=200)
        {
	        for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=read();
	        memset(dp,0,sizeof(dp));
	        for(int i=1;i<=n;i++)
	            for(int j=0;j<=n/2&&j<=i;j++)
	                for(int k=0;k<=n/2&&k<=i;k++)
	                {
	                    int l=i-j-k;
	                    if(l<0) break;
	                    if(l>n/2) continue;
						if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
						if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
						if(l!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
	            	}
			for(int i=0;i<=n/2;i++)
	            for(int j=0;j<=n/2;j++)
	                if(n-i-j<=n/2) ans=max(ans,dp[n][i][j]);
	        cout<<ans<<"\n";
        }
        else 
        {
        	bool f1=true,f2=true;
        	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i],f1=(!b[i]&&!c[i]),f2=!c[i];
        	if(f1)
        	{
        		sort(a+1,a+n+1);
        		int sum=0;
        		for(int i=1;i<=n/2;i++) sum+=a[i];
        		cout<<sum<<"\n";
			}
			else if(f2)
			{
				memset(f,0,sizeof(f));
				for(int i=0;i<=n;i++)
					for(int j=1;j<=n/2;j++)
					{
						int k=i-j;
						if(k<0) break; 
						if(k>n/2) continue;
						if(j!=0) f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]);
						if(k!=0) f[i][j]=max(f[i][j],f[i-1][j]+b[i]);
					}
				cout<<f[n][n/2]<<"\n";
			}
		}
    }
    return 0;
}