#include <bits/stdc++.h> 
using namespace std;
int n,m,num[500];
struct s
{
	int num,a,set;
}s[500];
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","r",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++)	{
		cin >> s[i].num;
		s[i].a=s[i].num;
		num[i]=s[i].num;
	}
	sort(num+1,num+n*m+1);
	
	int t=1;
	for(int i=n*m;i>1;i--)
	{
		s[t].set=num[i];
		t++;
		
	}
	
	int c=-1,r=1
	;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			r=n;
			for(int j=n;j>=1;j--)
			{
				
				if(s[j].set==s[1].a)
				{
					r=j;
					c=i-1;
					break;
				}
			}
		}
		else
		{
			
			r=1;
			for(int j=1;j<=n;j++)
			{
				if(s[j].set==s[1].a)
				{
					r=j;
					c=i-1;
					break;
				}
			}
		}
		c++;
	}
	cout << c-1 << " " << r ;
	return 0;
}
