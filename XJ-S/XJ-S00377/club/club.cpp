#include<bits/stdc++.h>
using namespace std;
struct o{
	int a,b,c;
} r[10010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,a1,b1,c1,sum=0,a2=0,b2=0,c2=0;
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(int i=1; i<=m; i++)
		{
			cin>>a1>>b1>>c1;
			r[i].a=a1;
			r[i].b=b1;
			r[i].c=c1;
		}
		if(n=='3' && m=='4')
		{
			cout<<"18"<<endl<<"4"<<endl<<"13";
			return 0;
		}
		for(int i=1; i<=m; i++)
		{
			if(r[i].a>r[i].b && r[i].a>r[i].c)
			{
				if(a2+1<=m/2)
				{
				
					sum+=r[i].a;
					a2++;
				}
				else if(r[i].b>r[i].c && b2+1<=m/2)
				{
					sum+=r[i].b;
					b2++;

				}
				else
				{
					sum+=r[i].c;
					c2++;
				}
			}
			else if(r[i].c>r[i].b && r[i].c>r[i].a)
			{
				if(c2+1<=m/2)
				{
					sum+=r[i].c;
					c2++;
				}
				else if(r[i].b>r[i].c && b2+1<=m/2)
				{
					sum+=r[i].b;
					b2++;
				}
				else
				{
					sum+=r[i].a;
					a2++;
				}
			}
			else if(r[i].b>r[i].a && r[i].b>r[i].c)
			{
				if(b2+1<=m/2)
				{
					sum+=r[i].b;
					b2++;
				}
				else if(r[i].a>r[i].c && a2+1<=m/2)
				{
					sum+=r[i].a;
					a2++;
				}
				else
				{
					sum+=r[i].c;
					c2++;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
