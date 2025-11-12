#include<bits/stdc++.h>
using namespace std;
struct qwq
{
	int a,b,c;
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
	cin>>t; 
	while(t!=0)
	{
	    int aa[100002]={0},bb[100002]={0},cc[100002]={0};	
	    int n,ans=0,an=0,z=0,h=0,p=0;
		t--;
		cin>>n;
		int m,u,v,d; 
		int cz[n+1];
		qwq k[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i].a>>k[i].b>>k[i].c;
			an=max(k[i].a,max(k[i].b,k[i].c));
			ans+=an;
			if(an==k[i].a){z++;aa[z]=i;}
			else if(an==k[i].b){h++;bb[h]=i;}
			else if(an==k[i].c){p++;cc[p]=i;}
			
		}
		if((2*z<=n)&&(2*h<=n)&&(2*p<=n))
		{
		    cout<<ans<<endl;continue;
		}
		if(2*z>n)
		{
			m=z-n/2;
			for(int i=1;i<=z;i++)
			{
				d=aa[i];
				cz[d]=min(k[d].a-k[d].b,k[d].a-k[d].c);
			}
			for(int i=m;i>0;i--)
			{
			    u=20000000;
				for(int j=1;j<=z;j++)
			    {
				    d=aa[j];
					if(cz[d]<u)
					{
						u=cz[d];v=d;
					}
				}
				ans-=u;aa[v]=0;z-=1;
				if(u=k[v].a-k[v].b)
				{
					h+=1;
					bb[h]=v;
				}
				if(u=k[v].a-k[v].c){p+=1;cc[p]=v;}
			}
			if(2*h<=n)
			{
				cout<<ans<<endl;continue;
			}
			else if(2*h>n)
			{
				m=h-n/2;
				for(int i=1;i<=h;i++)
			    {
				    d=bb[i];
				    cz[d]=k[d].b-k[d].c;
			    }
				for(int i=m;i>0;i--)
			    {
			    u=200000000;
				for(int j=1;j<=h;j++)
			    {
				    d=bb[j];
					if(cz[d]<u)
					{
						u=cz[d];v=d;
					}
				}
				ans-=u;
		        }
		        cout<<ans<<endl;continue;
		}
	}
		else if(2*h>n)
		{
			m=h-n/2;
			for(int i=1;i<=h;i++)
			{
				d=bb[i];
				cz[d]=min(k[d].b-k[d].a,k[d].b-k[d].c);
			}
			for(int i=m;i>0;i--)
			{
			    u=200000000;
				for(int j=1;j<=h;j++)
			    {
				    d=bb[j];
					if(cz[d]<u)
					{
						u=cz[d];v=d;
					}
				}
				ans-=u;bb[v]=0;h-=1;
				if(u=k[v].b-k[v].a)
				{
					z+=1;
					aa[z]=v;
				}
				else if(u=k[v].b-k[v].c){p+=1;cc[p]=v;}
			}
			if(2*z<=n)
			{
				cout<<ans<<endl;continue;
			}
			else if(2*z>n)
			{
				m=z-n/2;
				for(int i=1;i<=z;i++)
			    {
				    d=aa[i];
				    cz[d]=k[d].a-k[d].c;
			    }
				for(int i=m;i>0;i--)
			    {
			    u=200000000;
				for(int j=1;j<=z;j++)
			    {
				    d=aa[j];
					if(cz[d]<u)
					{
						u=cz[d];v=d;
					}
				}
				ans-=u;
		        }
		        cout<<ans<<endl;continue;
		    }
		}
		else if(2*p>n)
		{
			m=p-n/2;
			for(int i=1;i<=p;i++)
			{
				d=cc[i];
				cz[d]=min(k[d].c-k[d].b,k[d].c-k[d].c);
			}
			for(int i=m;i>0;i--)
			{
			    u=200000000;
				for(int j=1;j<=p;j++)
			    {
				    d=cc[j];
					if(cz[d]<u)
					{
						u=cz[d];v=d;
					}
				}
				ans-=u;cc[v]=0;p-=1;
				if(u=k[v].c-k[v].b)
				{
					h+=1;
					bb[h]=v;
				}
				else if(u=k[v].c-k[v].a){z+=1;aa[p]=v;}
			}
			if(2*h<=n)
			{
				cout<<ans<<endl;continue;
			}
			if(2*h>n)
			{
				m=h-n/2;
				for(int i=1;i<=h;i++)
			    {
				    d=bb[i];
				    cz[d]=k[d].b-k[d].c;
			    }
				for(int i=m;i>0;i--)
			    {
			    u=200000000;
				for(int j=1;j<=h;j++)
			    {
				    d=bb[j];
					if(cz[d]<u)
					{
						u=cz[d];v=d;
					}
				}
				ans-=u;
		        }
		        cout<<ans<<endl;continue;
		}
	}
    }
}
