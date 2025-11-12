#include<bits/stdc++.h>
using namespace std;
char kinchar,kinf;
long long kinnum;
const int yu=998244353;
inline long long kin()
{
	kinf=1;
	kinchar=getchar();
	kinnum=0;
	if(!('0'<=kinchar&&kinchar<='9'))
	{
		kinf=-1;
		kinchar=getchar();
	}
	while(('0'<=kinchar&&kinchar<='9'))
	{
		kinnum=kinnum*10+kinchar-'0';
		kinchar=getchar();
	}
	return kinnum*kinf;
}
bool usd[99];
long long l[99],ji[99],pl[99],n,sum,m;
char cl[99];
void dfs(long long p)
{
	for(int i=1;i<=n;i++)
	{
		if(!usd[i])
		{
			usd[i]=1;
			pl[p]=i;
			if(p==n)
			{
				int ans=0;
				for(int j=1;j<=n;j++)
				{
					if((!cl[j])&&ji[j]<l[pl[j]])
					{
						ans++;
					}
				}
				if(ans>=m)
					sum=(sum+1)%yu;
			}
			else
			{
				dfs(p+1);
			}
			usd[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>cl;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	cl[0]-='0';
	ji[1]=!cl[0];
	
	for(int i=2;i<=n;i++)
	{
		cl[i-1]-='0';
		ji[i]+=1-cl[i-1]+ji[i-1];
	}
	dfs(1);
	
	cout<<sum;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

