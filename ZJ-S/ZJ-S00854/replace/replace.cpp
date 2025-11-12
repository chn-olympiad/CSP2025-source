#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n,q,ans=0;
bool aa[30]={};
struct ss{
	string a,b;
}x[200005],k;
int sss(ss k,int d,bool a)
{
	if(k.a==k.b)
	{
		ans++;
		return 0;
	}
	if(d>=k.a.size())
		return 0;
	if(a)
		return 0;
	for(int i=0;i<k.a.size();i++)
	{
		if(aa[k.a[i]-'a'])
		{
			for(int j=0;j<n;j++)
			{
				if(k.a.size()-x[j].a.size()+x[j].b.size()!=k.b.size())
					continue;
				bool e=1;
				ss dd=k;
				for(int i1=0;i1<x[j].a.size();i1++)
				{
					if(x[j].a[i1]!=k.a[i1+i])
					{
						e=0;
						break;
					}
					dd.a[i1+i]=x[j].b[i1];
				}
				if(e==1)
				{
					sss(dd,i+x[j].a.size(),1);
				}
			}
		}
		if(k.a[i]!=k.b[i])
		{
			break;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>x[i].a>>x[i].b;
		aa[x[i].a[0]-'a']=1;
	}
	for(int i=0;i<q;i++)
	{
		cin>>k.a>>k.b;
		sss(k,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}