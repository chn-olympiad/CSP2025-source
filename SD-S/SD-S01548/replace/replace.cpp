#include<iostream>
using namespace std;
const int N=2e5+10;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,q;
struct Str{
	string a,b;
	int len;
}s[N]; 
string ft[N];
string ed[N]; 
int main()
{

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b; 
		s[i].len=s[i].a.size();
	}
	while(q--)
	{
		string t1,t2;
		int cnt=0;
		cin>>t1>>t2;
		int lent=t1.size();
		ft[0]=t1[0];
		for(int i=1;i<lent;i++)
		{
			ft[i]=ft[i-1]+t1[i];

			//ft2[i]=ft2[i-1]+t2[i];
		}
		for(int i=lent-1;i>=0;i--)
		{
			ed[i]=t1[i]+ed[i+1];
			//ed2[i]=t2[i]+ed2[i+1];
		}
		//cout<<t1<<' '<<t2<<'\n';
		for(int i=0;i<lent;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i+s[j].len>lent)continue;
				
				if(i>=1)
				{
					//cout<<ft1[i-1]<<' '<<s[j].a<<' '<<ed1[i+s[j].len]<<'\n';
					if(ft[i-1]+s[j].a+ed[i+s[j].len]==t1)
					{
						//cout<<"md"<<ft1[i-1]+s[j].b+ed1[i+s[j].len]<<' '<<t2<<'\n';
						if(ft[i-1]+s[j].b+ed[i+s[j].len]==t2)
							cnt++;
					}
				}
				else 
				{
					//cout<<s[j].a+ed1[i+s[j].len]<<' '<<t1<<'\n';
					if(s[j].a+ed[i+s[j].len]==t1)
					{
						//cout<<s[j].b+ed[i+s[j].len]<<' '<<t2<<'\n';
						if(s[j].b+ed[i+s[j].len]==t2)
						cnt++; 
					}
				}
		
			}
		}
		cout<<cnt<<'\n';

	}
	return 0;
}

