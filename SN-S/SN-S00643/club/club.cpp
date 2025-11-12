#include<bits/stdc++.h>
using namespace std;
int n,a,b[10]={0},jl[4]={0},ans=0;
int c=0;
bool ab()
{
	int q=0;
	for(int i=1;i<4;i++)
	{
		if(b[i]==c)
		{
			q++;
		}
	}
	if(q>2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int o()
{
	int v=4;
	int x=0,ji[4]={},p[4]={};
	while(v--)
	{
		for(int i=1;i<4;i++)
		{
			ji[i]=jl[i];
			if(p[i]!=0)
			{
				ji[i]++;
			}
			x=max(x,ji[i]);
		}
		for(int i=1;i<4;i++)
		{
			if(ji[i]==x)
			{
				return i;
			}
		}
	}

}
int main()
{
	fre("club.in","r",stdin);
	fre("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a;
        for(int j=0;j<a;j++)
        {

            for(int k=1;k<4;k++)
            {
                cin>>b[k];
                c=max(c,b[k]);
            }
            for(int k=1;k<4;k++)
            {
            	ab();
            	if(!ab)
            	{
            		if(b[k]==c)
					{
						ans+=c;
            			jl[k]++;
					}
				}
				else
				{
					if(b[k]==c)
					{
						p[k]++;
						o();

					}
				}
            }
        }
        int z=0;
        for(int j=1;j<4;j++)
    	{
            z=max(z,jl[j]);
        }
        if(z<=a/2)
        {
            cout<<ans;
        }
    }
	return 0;
}
