#include<stdio.h>
#include<queue>
namespace mns
{
	std::priority_queue<std::pair<int,int> > q;
	int ls[100000][3];
	int max(int a,int b)
	{
		return (a>b?a:b);
	}
	int max(int a,int b,int c)
	{
		return max(a,max(b,c));
	}
	int mid(int a,int b,int c)
	{
		if(b>=c&&b>=a)
		{
			return max(a,c);
		}
		if(b>=c&&b<=a||b<=c&&b>=a)
		{
			return b;
		}
		return (a<c?a:c);
	}
	void func()
	{
		int n,i,ans=0,mx,md,c1=0,c2=0,c3=0,r;
		std::pair<int,int>tmp;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",ls[i],ls[i]+1,ls[i]+2);
			mx=max(ls[i][0],ls[i][1],ls[i][2]);
			md=mid(ls[i][0],ls[i][1],ls[i][2]);
			if(mx==ls[i][0])
			{
				c1++;
				r=0;
			}
			else if(mx==ls[i][1])
			{
				c2++;
				r=1;
			}
			else
			{
				c3++;
				r=2;
			}
			ans+=mx;
			q.push(std::make_pair(md-mx,r));
		}
		if(max(c1,c2,c3)>n/2)
		{
			if(c1>n/2)
			{
				r=0;
			}
			else if(c2>n/2)
			{
				r=1;
			}
			else
			{
				r=2;
			}
			for(i=max(c1,c2,c3)-n/2;i>0;--i)
			{
				tmp=q.top();
				if(tmp.second==r)
				{
					ans+=q.top().first;
				}
				else
				{
					i++;
				}
				q.pop();
			}
		}
		printf("%d\n",ans);
	}
	int main()
	{
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			while(!q.empty())
			{
				q.pop();
			}
			func();
		}
		return 0;
	}
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	mns::main();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
