#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
struct t
{
	string x,y;
	int xbi,ybi,db;
}a[200005];
cmp(t a,t b)
{
	return a.db<b.db;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
		for(int j=0;j<a[i].x.length();j++)
		{
			if(a[i].x[j]=='b') 
			{
				a[i].xbi=j;
				break;
			}
		}
		for(int j=0;j<a[i].y.length();j++)
		{
			if(a[i].y[j]=='b') 
			{
				a[i].ybi=j;
				break;
			}
		}
		a[i].db=a[i].ybi-a[i].xbi;
	}
	t t1;
	long long ans=0;
	while(q--)
	{
		ans=0;
		cin>>t1.x>>t1.y;
		for(int j=0;j<t1.x.length();j++)
		{
			if(t1.x[j]=='b') 
			{
				t1.xbi=j;
				break;
			}
		}
		for(int j=0;j<t1.y.length();j++)
		{
			if(t1.y[j]=='b') 
			{
				t1.ybi=j;
				break;
			}
		}
		t1.db=t1.ybi-t1.xbi;
		for(int i=0;i<n;i++)
		{
			if(a[i].db=t1.db&&t1.xbi>=a[i].xbi&&t1.x.length()-t1.xbi>=a[i].x.length()-a[i].xbi)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
