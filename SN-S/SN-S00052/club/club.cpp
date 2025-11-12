//刘家豪  SN-S00052 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node
{
	int a;
	int b;
	int c;
};
bool cmp(node p,node q)
{
	return p.a>q.a;
}
bool nmp(node p,node q)
{
	return p.b>q.b;
}
bool mmp(node p,node q)
{
	return p.c>q.c;
}
bool cap(node p ,node q)
{
	return p.a<p.a;
}
bool cbp(node p ,node q)
{
	return p.b<p.b;
}
bool cdp(node p ,node q)
{
	return p.c<p.c;
}
void e(node f,int u,int v,int w,node sum)
{
	if(u<=n/2)
	{
		if(f.a>f.b&&f.a>f.c)
		{
			sum.a+=f.a;
			u++;
		}
		if(f.a==f.b&&f.a==f.c)
		{
			sum.a+=f.a;
			u++;
		}
		if(f.a<f.b&&f.a<f.c&&f.b>=f.c&&v<=n/2)
		{
			sum.a+=f.b;
			v++;
		}
		if(f.a<f.b&&f.a<f.c&&f.c>f.b&&w<=n/2)
		{
			sum.a+=f.c;
			w++;
		}
		else
		{
			sum.a+=f.a;
		}
	}
	if(v<=n/2)	
	{
		if(f.b>=f.c)
		{
			sum.a+=f.b;
			v++;
		}
		if(f.b<f.c&&w<=n/2)
		{
			sum.a+=f.c;
			w++;
		}
		else
		{
			sum.a=sum.a+f.b;
		}
	}

}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
    while(t--)
	{	
	    node d[100005];
	    int u,v,w;
	    node sum;
		cin >> n;
        for(int i=0;i<n;i++)
        {
        	cin >> d[i].a>>d[i].b>>d[i].c;
		}
		sort(d,d+n,cap);
		for(int i=0;i<n;i++)
		{
			if(d[i].a==0||d[i].b==0||d[i].c==0)
			{
				if(d[i].a==0)
			   {
			    	sort(d,d+n,cbp);
				    if(d[i].b==0)
				   { 
				    	sort(d,d+n,cdp);
					    if(d[i].c==0)
					   {
					   	 sort(d,d+n,cap);
						 break;
					   }
					   sort(d,d+n,mmp);
					   break;
				    }
				    sort(d,d+n,nmp);
				    break;
			    }
			    if(d[i].b==0)
			   {
				        sort(d,d+n,cdp);
					    if(d[i].c==0)
					   {
					   	 sort(d,d+n,cap);
						 break;
					   }
					   sort(d,d+n,mmp);
					   break;
				}
			    sort(d,d+n,cmp);
			    break;
		    }
		}
		for(int i=0;i<n;i++)
		{
			e(d[i],u,v,w,sum);
		}
		cout << sum.a;
    }
	return 0;
}
