#include<bits/stdc++.h>
using namespace std;
int n,t,a,b,c,ca,cb,cc;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int maxn=n/2;
		ca=cb=cc=0;
		for(int i=1;i<=n;i++)
		{
			
			cin>>a>>b>>c;
			//1
			if(a>b&&b>c)
			{
				if(ca<maxn)
				{
					ca++;
				}
				else if(cb<maxn)
				{
					cb++;
				}
				else if(cc<maxn)
				{
					cc++;
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
			//2
			else if(a>c&&c>b)
			{
				if(ca<maxn)
				{
					ca++;
				}
				else if(cc<maxn)
				{
					cc++;
				}
				else if(cb<maxn)
				{
					cb++;
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
			//3
			else if(b>a&&a>c)
			{
				if(cb<maxn)
				{
					cb++;
				}
				else if(ca<maxn)
				{
					ca++;
				}
				else if(cc<maxn)
				{
					cc++;
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
			//4
			else if(b>c&&c>a)
			{
				if(cb<maxn)
				{
					cb++;
				}
				else if(cc<maxn)
				{
					cc++;
				}
				else if(ca<maxn)
				{
					ca++;
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
			//5
			else if(c>a&&a>b)
			{
				if(cc<maxn)
				{
					cc++;
				}
				else if(ca<maxn)
				{
					ca++;
				}
				else if(cb<maxn)
				{
					cb++;
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
			//6
			else if(c>b&&b>a)
			{
				if(cc<maxn)
				{
					cc++;
				}
				else if(cb<maxn)
				{
					cb++;
				}
				else if(ca<maxn)
				{
					ca++;
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
			//7
			else
			{
				if(ca<maxn) ca++;
				else if(cb<maxn) cb++;
				else if(cc<maxn) cc++;
				else
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<ca+cb+cc;
	}
	return 0;
}
