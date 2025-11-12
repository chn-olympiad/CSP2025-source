#include<bits/stdc++.h>//t4
using namespace std;
const int N=510;
const int MOD=998244353;
string c;
int a,b,d[N],d1[N],e,f,g,h;
int o[N];
void dfs(int x,int y,int z)
{
	//cout<<x<<" "<<y<<" "<<z<<"\n";
	if(x>a)
	{
		if(y>=b)
		{
			int u=0;
			for(int i=1;i<=3;i++)
			{
				if(c[i-1]=='0')
				{
					u++;
				}
				else
				{
					if(u>=d[o[i]])
					{
						return ;
					}
				}
			}
			
			e++;
			e=e%MOD;
		}
		return ;
	}
	for(int i=1;i<=a;i++)
	{
		/*
		if(z>=d[i])
		{
			continue;
		}
		*/
		if(d1[i]!=0)
		{
			continue;
		}
		if(c[i-1]=='0')
		{
			d1[i]=2;
			o[x]=i;
			dfs(x+1,y,z+1);
			d1[i]=0;
		}
		else
		{
			d1[i]=1;
			o[x]=i;
			dfs(x+1,y+1,z);
			d1[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>a>>b;
	cin>>c;
	for(int i=1;i<=a;i++)
	{
		cin>>d[i];
		d1[i]=0;
	}
	sort(d+1,d+1+a);
	if(a<=18)
	{
		e=0;
		dfs(1,0,0);//第几天，当前已录取人数，当前面试失败人数 
		cout<<e;
		return 0;
	}
	cout<<rand();
	
	return 0;
}
