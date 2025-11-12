#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int v[4],e=0,b=0,rt=0,v4=0,v5=0;
		for(int g=1;g<=n;g++)
		{
			int z[4]={0};
		    for(int j=1;j<=3;j++)
		    {
			    cin>>v[j];
		    }
		    if((v[1]>1 && v[2]==0 && v[3]==0) || (v[1]==0 && v[2]>1 && v[3]==0) || (v[1]==0 && v[2]==0 && v[3]>1))
		    {
		    	b++;
			}
			if(v[1]<=1 && v[2]<=1 && v[3]<=1)
			{
			    
			}
			else
			{
		        int p=v[1],v1=1;
		        int u[4];
		        u[1]=v[1];
		        u[2]=v[2];
		        u[3]=v[3];
			    for(int r=2;r<=3;r++)
			    {
			    	if(p<=v[r])
				    {
					    p=v[r];
					    v1=r;
				    }
	            }
	            if(z[v1]>n/2)
	            {
			        u[v1]=0;
	        	    for(int r=1;r<=3;i++)
			        {
				        if(p<=v[r])
				        {
					        p=v[r];
					       v1=r;
				        }
	                }
	                z[v1]++;
			    }
	            else
	            {
				    z[v1]++;
			    }
			    if(b==1 && z[v1]==n/2)
	            {
	                e-=v5;
	                e+=rt;
			    }
			    e+=p;
			    u[v1]=0;
			    v5=p;
			    if(u[1]==0)
			    {
			        u[1]==u[2];
				    u[2]==u[3];
				    u[3]==0;
			    }
			    else if(u[2]==0)
			    {
				    u[2]==u[3];
				    u[3]==0;
			    }
			    rt=max(u[1],u[2]);
		    }
	    }
	    cout<<e<<endl;
	}
	return 0;
}




























//The end.(17:30)
//By the way,I can't make sure it can work.(18:04)





















































//Goodbye CSP,this is my last time to see you.
//You know I spent 2 years and 179 days on you.
//I am sorry but I should go now.
//Have a good night.
//Bye.(18:30)
