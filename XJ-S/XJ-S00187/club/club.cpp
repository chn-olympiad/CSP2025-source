#include<bits/stdc++.h>
using namespace std;
struct m
{
	int a,b,c;
}t[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q,n,i,j,ttt,tttt,sum,num1,num;
	cin>>q;
	t[0].a=2147483647;
	t[0].b=2147483647;
	t[0].c=2147483647;
	while(q--)
	{
		sum=0;num1=0;ttt=0;tttt=0; 
		cin>>n;
		int tt=n/2;
		for(i=1;i<=n;i++)
		{
			cin>>t[i].a>>t[i].b>>t[i].c;
			if(t[i].a!=0) ttt=1;
			if(t[i].c!=0) tttt=1;
		}
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=i;j++)
			{
				if(t[j-1].a<t[j].a) swap(t[j-1],t[j]);
				else
				{
					if(t[j-1].a==t[j].a&&t[j-1].b<t[j].b) swap(t[j-1],t[j]);
					else
					{
						if(t[j-1].a==t[j].a&&t[j-1].b==t[j].b&&t[j-1].c<t[j].c) swap(t[j-1],t[j]);
					}
				}
			}
		}
		if(ttt==0&&tttt==0)
		{
			for(i=1;i<=tt;i++) sum+=t[i].b;
			cout<<sum<<endl; 
		}
		else
		{
			if(ttt==0)
			{
				for(i=1;i<=n;i++)
				{
					if(num<tt&&t[i].a>t[i].b)
					{
						sum+=t[i].a;
						num++;
					}
					else
					{
						if(num1<tt)
						{
							sum+=t[i].b;
							num1++;
						}
					}
				}
				cout<<sum<<endl; 
			}
			else
			{
				int num2=0;
				for(i=1;i<=n;i++)
				{
					if(num<tt&&t[i].a>t[i].b&&t[i].a>t[i].c)
					{
						sum+=t[i].a;
						num++;
					}
					else
					{
						if(num1<tt&&t[i].b>t[i].a&&t[i].b>t[i].c)
						{
							sum+=t[i].b;
							num1++;
						}
						else
						{
							if(num2<tt&&t[i].c>t[i].a&&t[i].c>t[i].b)
							{
								sum+=t[i].c;
								num2++;
							}
							else
							{
								if(num<tt&&t[i+1].a<t[i+1].b&&t[i+1].a<t[i+1].c) {sum+=t[i].a;num++;}
								else if(num1<tt&&t[i+1].b<t[i+1].a&&t[i+1].b<t[i+1].c) {sum+=t[i].b;num1++;}
								 else if(num2<tt&&t[i+1].c<t[i+1].a&&t[i+1].c<t[i+1].b) {sum+=t[i].c;num2++;}
							}
						}
					}
				}
				cout<<sum<<endl;
			}
		} 
	}
	return 0;
}
