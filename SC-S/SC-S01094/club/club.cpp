#include<bits/stdc++.h>
using namespace std;
struct node
{
	int f;
	int s;
	int t;
}x[2000005];
int a,b,c,d,e,ma=0;
int n1=0,n2=0,n3=0;
int yy1[1000000],yy2[1000000],yy3[1000000];
void tx1(int j)
{
	if(n1+1<=b/2)
	{
		n1=n1+1;
		yy1[n1]=j;
		return;
	}
	int ly=-1,mib,mic,sw;
	for(int k=1;k<=n1;k=k+1)
	{
		int u=yy1[k];
		if(x[j].f+x[u].s-x[u].f>ly)
		{
			ly=x[j].f+x[u].s-x[u].f;
			mib=u;
			mic=1;
			sw=k;
		}
		if(x[j].f+x[u].t-x[u].f>ly)
		{
			ly=x[j].f+x[u].t-x[u].f;
			mib=u;
			mic=2;
			sw=k;
		}
	}
	if(ly>=1)
	{
		if(mic==1)
		{
			n2=n2+1;
			yy2[n2]=mib;
		}
		if(mic==2)
		{
			n3=n3+1;
			yy3[n3]=mib;
		}
		yy1[sw]=j;
	}
	else if(x[j].s>=x[j].t)
	{
		n2=n2+1;
		yy2[n2]=j;
	}
	else
	{
		n3=n3+1;
		yy3[n3]=j;
	}
	return;
}
void tx2(int j)
{
	if(n2+1<=b/2)
	{
		n2=n2+1;
		yy2[n2]=j;
		return;
	}
	int ly=INT_MIN,mib,mic,sw;
	for(int k=1;k<=n2;k=k+1)
	{
		int u=yy2[k];
		if(x[j].s+x[u].f-x[u].s>ly)
		{
			ly=x[j].s+x[u].f-x[u].s;
			mib=u;
			mic=1;
			sw=k;
		}
		if(x[j].s+x[u].t-x[u].s>ly)
		{
			ly=x[j].s+x[u].t-x[u].s;
			mib=u;
			mic=2;
			sw=k;
		}
	}
	if(ly>=1)
	{
		if(mic==1)
		{
			n1=n1+1;
			yy1[n1]=mib;
		}
		if(mic==2)
		{
			n3=n3+1;
			yy3[n3]=mib;
		}
		yy2[sw]=j;
	}
	else if(x[j].f>=x[j].t)
	{
		n1=n1+1;
		yy1[n1]=j;
	}
	else
	{
		n3=n3+1;
		yy3[n3]=j;
	}
	return;
}



void tx3(int j)
{
	if(n3+1<=b/2)
	{
		n3=n3+1;
		yy3[n3]=j;
		return;
	}
	int ly=INT_MIN,mib,mic,sw;
	for(int k=1;k<=n3;k=k+1)
	{
		int u=yy3[k];
		if(x[j].t+x[u].f-x[u].t>ly)
		{
			ly=x[j].t+x[u].f-x[u].t;
			mib=u;
			mic=1;
			sw=k;
		}
		if(x[j].t+x[u].s-x[u].t>ly)
		{
			ly=x[j].t+x[u].s-x[u].t;
			mib=u;
			mic=2;
			sw=k;
		}
	}
	if(ly>=1)
	{
		if(mic==1)
		{
			n1=n1+1;
			yy1[n1]=mib;
		}
		if(mic==2)
		{
			n2=n2+1;
			yy2[n2]=mib;
		}
		yy3[sw]=j;
	}
	else if(x[j].f>=x[j].s)
	{
		n1=n1+1;
		yy1[n1]=j;
	}
	else
	{
		n2=n2+1;
		yy2[n2]=j;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i=i+1)
	{
		ma=0;
		n1=0,n2=0,n3=0;
		cin>>b;
		for(int j=1;j<=b;j=j+1)
		{
			cin>>x[j].f>>x[j].s>>x[j].t;
		}
		for(int o=1;o<=b;o=o+1)
		{
			if(max(max(x[o].f,x[o].s),x[o].t)==x[o].f)
			{
				tx1(o);
			}
			else if(max(max(x[o].f,x[o].s),x[o].t)==x[o].s)
			{
				tx2(o);
			}
			else if(max(max(x[o].f,x[o].s),x[o].t)==x[o].t)
			{
				tx3(o);
			}
			/*for(int j=1;j<=n1;j=j+1)
			{
				cout<<yy1[j]<<" ";
			}
			cout<<endl;
			for(int j=1;j<=n2;j=j+1)
			{
				cout<<yy2[j]<<" ";
			}
			cout<<endl;
			for(int j=1;j<=n3;j=j+1)
			{
				cout<<yy3[j]<<" ";
			}
			cout<<endl<<endl;*/
		}
		for(int j=1;j<=n1;j=j+1)
		{
			ma=ma+x[yy1[j]].f;
		}
		for(int j=1;j<=n2;j=j+1)
		{
			ma=ma+x[yy2[j]].s;
		}
		for(int j=1;j<=n3;j=j+1)
		{
			ma=ma+x[yy3[j]].t;
		}
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}