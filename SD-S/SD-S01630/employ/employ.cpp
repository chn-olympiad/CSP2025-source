#include<iostream>
#include<cmath>
using namespace std;
int n,m;
string s;
int c[800];
bool emp[800];
int cnt;
void dfs(int days,int emled,bool empd[])
{
	if(emled>=m)
	{
		cnt++;
	}
	if(days>n)
	{
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(empd[i]==0)
		{
			empd[i]=1;
			if((days-emled<=c[i])&&(s[days]=='1'))
			{
				for(int j=0;j<n;j++)
				{
					if(empd[j]==0)
					{
						empd[j]=1;
						dfs(days+1,emled+1,empd);
						empd[j]=0;
					}
				}
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					if(empd[j]==0)
					{
						empd[j]=1;
						dfs(days+1,emled,empd);
						empd[j]=0;
					}
				}
			}
			empd[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i]; 
	}
	dfs(0,0,emp);
	cout<<cnt;
	return 0;
}
