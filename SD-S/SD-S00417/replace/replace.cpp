#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e5+10;
int n,q;
string s[5][N],tx,ty;
int mp[N];
bool check(int l,int r,int id)
{
	string ss="";
	for(int i=0;i<l;i++)
	{
		ss+=tx[i];
	}
	ss+=s[2][id];
	for(int i=r+1;i<tx.size();i++)
	{
		ss+=tx[i];
	}
	return ss==ty;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
		mp[s[1][i].size()]=1;
	}
	while(q--)
	{
		cin>>tx>>ty;
		int len=tx.size(),ans=0;
		for(int i=0;i<len;i++)
		{
			string ss=""; 
			for(int j=i;j<len;j++)
			{
				ss+=tx[j];
				if(mp[j-i+1])
				{
					for(int k=1;k<=n;k++)
					{
						if(s[1][k].size()==j-i+1&&ss==s[1][k])
						{
							if(check(i,j,k)) 
							{
//								cout<<"dxj: "<<k<<"\n";
								ans++;	
							}
						}
					}
				} 
			}
		}
		cout<<ans<<"\n";		
	}

	return 0;
}

