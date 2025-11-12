/*#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
int p[maxn];
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int b,c;
		scanf("%d%d%d",&p[i],&b,&c);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		sort(p,p+n);
		int ans=0;
		int l=n/2;
		for(int i=1;i<l;i++)
			ans+=p[i];
		printf("%d\n",ans);
	}
}*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
int n;
struct Node{
	int a;
	int b;
	Node(int a=0,int b=0):a(a),b(b){}
	bool operator <(const Node &l)const{
		return((a<l.a)||(a==l.a&&b>l.b));
	}
};
priority_queue <Node>p;
void init()
{
	while(!p.empty())
		p.pop();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int ai,bi,c;
		scanf("%d%d%d",&ai,&bi,&c);
		p.push(Node(ai,bi));
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int sum1=0,sum2=0;
		init();
		int ans=0;
		int l=n/2;
		while(!p.empty())
		{
//			cout<<ans<<" "<<"^"<<sum1<<"^^"<<sum2<<" ";
			Node x=p.top();
			p.pop();
			if(x.a>=x.b)
			{
				if(sum1<l)
				{
					ans+=x.a;
					sum1++;
				}
				else
				{
					ans+=x.b;
					sum2++;
				}
			}
			else if(x.a<x.b)
			{
				if(sum2<l)
				{
					ans+=x.b;
					sum2++;
				}
				else
				{
					ans+=x.a;
					sum1++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
