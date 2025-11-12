#include<bits/stdc++.h>
using namespace std;
int n,i,j,z,ss,abc,aa,aac,xx,yy;
int ans=0;
int a[100][3];
struct xxx
{
	int shuz[3];
	int danw[3];
}b[100];
int c[100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	int y=n/2;
	for(i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(i=1;i<=n;i++)
	 {
	 	b[i].shuz[1]=a[i][1];
	 	b[i].shuz[2]=a[i][2];
	 	b[i].shuz[3]=a[i][3];
	 	for(ss=1;ss<=3;ss++)
	    {
		 b[i].danw[ss]=ss;
	    }
        for(j=1;j<=3;j++)
         for(z=1;z<=2;z++)
         {
         	abc=z;
         	if(b[i].shuz[abc]<b[i].shuz[abc+1]) 
		  {
		  	swap(b[i].shuz[abc],b[i].shuz[abc+1]);
		  	swap(b[i].danw[abc],b[i].danw[abc+1]);
		  }
		 }
	}

		for(i=1;i<=n;i++)
		 for(j=1;j<=n-1;j++)
           if(b[j].shuz[1]<b[j+1].shuz[1]) 
            swap(b[j],b[j+1]);
	 	for(i=1;i<=n;i++)
	 	{
	 		int ww=1;
        	if(c[b[i].danw[1]]<y)
           {
        	ans=ans+b[i].shuz[1];
        	c[b[i].danw[1]]++;
        	ww=0;
           }
            if(c[b[i].danw[1]]>=y && ww==1)
        	{
        		if(b[i].shuz[3]>b[i].shuz[2])
        			ans=ans+b[i].shuz[3];
                if(b[i].shuz[3]<=b[i].shuz[2])
        			ans=ans+b[i].shuz[2];	
			}
		}
	cout<<ans;
	return 0;
}



