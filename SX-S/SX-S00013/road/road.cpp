#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],c[20][10010],d[1010],e[1010],f[20];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k,pd=0;
    cin>>n>>m>>k;
     for(int i=1;i<=m;i++)
     {
     	int x,y,z;
     	cin>>x>>y>>z;
     	a[x][y]=z;
	 }
	 for(int i=1;i<=k;i++)
	 {
      for(int j=1;j<=n+1;j++)
      {
      	cin>>c[i][j];
	  }
	 }
	 cout<<1;
	 for(int i=2;i<=n;i++)
	 {

	 	if(a[1][i]!=0||a[i][1]!=0)
	 	{
	 		d[i]=max(a[1][i],a[i][1]);

		 }
		 	if(k!=0)
	 		{
	 			for(int j=1;j<=k;j++)
	 			{
	 				if((c[j][1+1]+c[j][i+1]+c[j][1])<d[i]||d[i]==0)
					 {
					 	d[i]=(c[j][1+1]+c[j][i+1]+c[j][1]);
					 	e[i]=j;
					  }
				 }
			 }
	 }
	 for(int i=1;i<=n-1;i++)
	 {
	 	int zx=-1,zxw=0;
	 	for(int j=2;j<=n;j++)
	 	{
          if(zx==-1&&d[j]!=-1){
          	zx=d[j];
          	zxw=j;
		  }
          if(d[j]<zx&&d[j]!=-1)
          {
          	zx=d[j];
          	zxw=j;
		  }
		 }
         ans=ans+zx;
         if(e[zxw]!=0)
         {
         	f[e[zxw]]++;
		 }
		 d[zxw]=-1;
         for(int j=1;j<=n;j++)
	     {
	 	  if(d[i]==-1) continue;
	 	if(a[zxw][j]!=0||a[j][zxw]!=0)
	 	{
	 		int p=0;
	 		p=max(a[zxw][j],a[j][zxw]);
            if(p!=0) d[j]=min(d[j],p);
		   }
	      }
	      	if(k!=0)
	 		{
	 			for(int j=1;j<=k;j++)
	 			{
	 				if(f[j]!=0)
	 				{
                       if((c[j][1+1]+c[j][i+1])<d[i])
                       {
                       	d[i]=c[j][1+1]+c[j][i+1];
					   }
					 }
					 else{
                     if((c[j][1+1]+c[j][i+1]+c[j][1])<d[i])
					 {
					 	d[i]=(c[j][1+1]+c[j][i+1]+c[j][1]);
					 	e[i]=j;
					  }
					 }
				 }
			 }
	 }
	 cout<<ans;
	return 0;
}