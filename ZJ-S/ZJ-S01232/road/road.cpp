#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m,k,c[1000010][11],d[11],l,r,f[11],a1[1010000],f1,z[11][2];
struct node
{
	int u,v,w;
}a[10000010];
int fa(int r1)
{
	if(r1==a1[r1])return r1;
	int t=fa(a1[r1]);
	a1[r1]=t;
	return t;
}
long long s,s1;
int fa1(int r1,int yu)
{
	if(r1==a1[r1])
	{
	    a1[r1]=yu;
	    return a1[r1];
    }
	int t=fa1(a1[r1],yu);
	a1[r1]=t;
	return t;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int read()
{
	char t;
	int q=0;
	while(t<'0'||t>'9')t=getchar();
	q=int(t)-48;
	t=getchar();
	while(t>='0'&&t<='9')q=q*10+int(t)-48,t=getchar();
	return q;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)a[i].u=read(),a[i].v=read(),a[i].w=read();
    l=n,r=m;
    for(int i=1;i<=k;i++)
    {
    	cin>>d[i];
    	for(int j=1;j<=n;j++)c[j][i]=read();
    	if(d[i]==0)z[i][0]=1;
		else f1++;
	}
	if(f1==0)
	{
	for(int i=1;i<=k;i++)
    {
    	if(d[i]==0)
    	{
    		l++;
    		for(int j=1;j<=n;j++)a[j+r].u=l,a[j+r].v=j,a[j+r].w=c[j][i];
    		r=r+n;
    		f[i]=1;
		}
	}
	sort(a+1,a+r+1,cmp);
	int q=0;
	for(int i=1;i<=l;i++)a1[i]=i;
	for(int i=1;i<=r;i++)
	{
		int t1=fa(a[i].u),t2=fa(a[i].v);
		if(a1[t1]!=a1[t2])
		{
			fa1(a1[t1],fa(a1[t2]));
			q++;
			s+=a[i].w;
		}
		if(q==l-1)break;
	}
	cout<<s;
    }
    else
    {
    	for(int i1=0;i1<=pow(2,f1)-1;i1++)
    	{
    		for(int i=1;i<=n;i++)a1[i]=i;
    		l=n,r=m,s1=0;
    		int jk=i1;
    		for(int j=1;j<=k;j++)
    		{
    			if(z[j][0]==1)z[j][1]=1;
    			else
    			{
    				z[j][1]=jk%2;
    				if(z[j][1]==1)s1+=d[j];
    				jk/=2;
				}
			}
    		for(int i=1;i<=k;i++)
            {
            	if(z[i][1]==1)
            	{
        	    	l++;
                	for(int j=1;j<=n;j++)a[j+r].u=l,a[j+r].v=j,a[j+r].w=c[j][i];
            		r=r+n;
            		f[i]=1;
	        	}
	        }
	        sort(a+1,a+r+1,cmp);
	        int q1=0;
	        for(int i=1;i<=l;i++)a1[i]=i;
	        for(int i=1;i<=r;i++)
	        {
	        	int t1=fa(a[i].u),t2=fa(a[i].v);
	        	if(a1[t1]!=a1[t2])
	        	{
	        		fa1(a1[t1],fa(a1[t2]));
	    		    q1++;
	    	    	s1+=a[i].w;
	        	}
	        	if(q1==l-1)break;
        	}
        	if(i1==0)s=s1;
        	else s=min(s,s1);
        }
    	cout<<s;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
