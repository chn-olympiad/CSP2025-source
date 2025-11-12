#include<bits/stdc++.h>
using namespace std;
int a[100010][4],b[4],sy[100010];
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
    	for(int i=1;i<=3;i++)
    	{
    		b[i]=0;
		}

    	ans=0;
    	int n;
    	cin>>n;
         for(int i=1;i<=n;i++)
         {
          cin>>a[i][1]>>a[i][2]>>a[i][3];
          if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
          {
          b[1]++;
          ans=ans+a[i][1];
          continue;
		  }
		  if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
          {
          b[2]++;
          ans=ans+a[i][2];
          continue;
		  }
		  if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
          {
          b[3]++;
          ans=ans+a[i][3];
          continue;
		  }
		 }

	if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2)
	{
		cout<<ans<<endl;
		continue;
	}
	else
	{
    int zd=0,st,wz=1;
    for(int i=1;i<=3;i++)
    {
    	if(b[i]>zd)
    	{
    		zd=b[i];
    		st=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][st]>=a[i][1]&&a[i][st]>=a[i][2]&&a[i][st]>=a[i][3])
		{
			sy[wz]=100000;
			for(int j=1;j<=3;j++)
			{
              if(j==st) continue;
              sy[wz]=min(sy[wz],a[i][st]-a[i][j]);
			}
			wz++;
		}
	}
    wz--;
    sort(sy+1,sy+wz+1);
    for(int i=1;i<=wz-n/2;i++)
    {
    ans=ans-sy[i];

	}
	}
	cout<<ans<<endl;
    }
	return 0;
}