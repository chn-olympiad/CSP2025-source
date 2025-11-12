#include <iostream>
#include <algorithm>
using namespace std;
int t,n,cnt;

int a[100005],b[100005],c[100005];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}
		if(n==2)
		{
			int a1=a[1]+a[2],b1=b[1]+b[2],c1=c[1]+c[2];
			int minn=min(min(a1,b1),c1);
			cout<<a1+b1+c1-minn<<endl;
		}
		else if(b[1]==b[2]&&b[2]==0&&c[1]==c[2]&&c[2]==0)
		{
			for(int i=1;i<=n;i++)
			{
				cnt+=a[i];
			}
			cout<<cnt/2;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]>b[i])
				{
					cnt+=a[i];
				}
				else
				{
					cnt+=b[i];
				}
			}
			cout<<cnt;
		}
	}
	
	return 0;
}