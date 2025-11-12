#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,ans,x,y,z;
priority_queue<int> q1,q2,q3;
int in()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9')
	  ch=getchar();
	while(ch<='9'&&ch>='0')
	  sum=sum*10+ch-48,ch=getchar();
	return sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		priority_queue<int> q1,q2,q3;
		n=in();
		ans=a=b=c=0;
		for(int i=1;i<=n;++i)
		{
			x=in(),y=in(),z=in();
			if(x>=y&&x>=z)
			  ++a,q1.push(-x+max(y,z));
			if(y>=x&&y>=z)
			  ++b,q2.push(-y+max(x,z));
			if(z>=x&&z>=y)
			  ++c,q3.push(-z+max(x,y));
			ans+=max(x,max(y,z));
		}
		for(int i=a;i>n/2;--i)
		  ans+=q1.top(),q1.pop();
		for(int i=b;i>n/2;--i)
		  ans+=q2.top(),q2.pop();
		for(int i=c;i>n/2;--i)
		  ans+=q3.top(),q3.pop();
		cout<<ans<<"\n";
	}
	return 0;
}
