#include<iostream>
#include<cstring>
using namespace std;
struct node{
	string x,y;
};
node a[200005];
string b,c,s;
bool f(int m,int y)
{
	for(int i=0;i<a[m].x.size();i++)
	{
		if(a[m].y[i]!=c[y+i])
		{
			return false;
		}
		if(b[y+i]!=a[m].x[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,k;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	while(q--)
	{
		cin>>b>>c;
		s=b;
		int ans=0;
		for(i=1;i<=n;i++)
		{
			int l=a[i].x.size();
			for(j=0;j<b.size();j++)
			{
				if(f(i,j))
				{
				for(k=0;k<l;k++)
				{
					s[j+k]=a[i].y[k];
				}
					if(s==c)
					{
						ans++;
						break;
					}
					else
					{
						s=b;
						j=l+j-1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
