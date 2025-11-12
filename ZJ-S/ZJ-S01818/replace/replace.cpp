#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,q;
string a[N],b[N];
string x[N],y[N];
map<string,ll> t1,t2;
void Str(ll j,ll t)
{
	if(t==1)
	{
		ll x,y;
		for(int i=0;i<a[j].size();i++)
		{
			if(a[j][i]!=b[j][i])
			{
				x=i;
				break;	
			}
		}
		for(int i=a[j].size()-1;i>=0;i--)
		{
			if(a[j][i]!=b[j][i])
			{
				y=i;
				break;	
			}
		}
		string s1="",s2="";
		for(int i=x;i<=y;i++)
		{
			s1+=a[j][i];
			s2+=b[j][i];
		}
	//	cout<<x<<" "<<y<<endl;
		a[j]=s1,b[j]=s2;
	}
	else
	{
		ll l,r;
		for(int i=0;i<x[j].size();i++)
		{
			if(x[j][i]!=y[j][i])
			{
				l=i;
				break;	
			}
		}
		for(int i=x[j].size()-1;i>=0;i--)
		{
			if(x[j][i]!=y[j][i])
			{
				r=i;
				break;	
			}
		}
		string s1="",s2="";
		for(int i=l;i<=r;i++)
		{
			s1+=x[j][i];
			s2+=y[j][i];
		}
		x[j]=s1,y[j]=s2;
	}
}
void St(string a,string b)
{
	ll l,r;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
		{
			l=i;
			break;	
		}
	}
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]!=b[i])
		{
			r=i;
			break;	
		}
	}
	string x1="",x2="",y="",z1="",z2="";
	for(int i=l;i<=r;i++)
	{
		x1+=a[i],x2+=b[i];
	}
	t1[x1]=1,t2[x2]=1;
	for(int i=0;i<=l;i++)
	{
		for(int j=i;j<l;j++)y+=a[j];
		z1=y+x1,z2=y+x2;
		for(int j=r;j<a.size();j++)
		{
			for(int k=r+1;k<=j;k++)
			{
				z1+=a[k],z2+=b[k];
			}
			t1[z1]=1,t2[z2]=1;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	if(q==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			//cout<<a[i]<<" "<<b[i]<<endl;
		}
		for(int i=1;i<=q;i++)
		{
			cin>>x[i]>>y[i];
			St(x[i],y[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(t1[a[i]]==1&&t2[b[i]]==1)ans++;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		Str(i,1);
		//cout<<a[i]<<" "<<b[i]<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		Str(i,0);
		//cout<<x[i]<<" "<<y[i]<<endl;
		ll ans=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==x[i]&&b[j]==y[i])ans++;
		}
		printf("%lld\n",ans);
	}
	
}