#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+3l;

struct xing{
	int disadvantage;
	int seat;
};


int a[N];
vector<int> b[N];
int at[N][3];
xing a1[N];
int yseat[N];
//judge
bool judge(xing a,xing b)
{
	if(a.disadvantage!=b.disadvantage)return a.disadvantage>b.disadvantage;
	else return (at[a.seat][2]-at[a.seat][1])>(at[b.seat][2]-at[b.seat][1]);
}
//pow
int pownumber[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262114,524288,1048576};
long long pow(int a,int b)
{
	if(b<=20)return pownumber[b];
	int ans=pownumber[20];
	for(int i=20;i<=b;i++)
	{
		ans*=a;
	}
	return ans;
}

//turn
int turn_ten(string a)
{
	int ans=0,n=a.size()-1;
	for(int i=n;i>=0;i--)
	{
		if(a[i]!='0')ans+=pow(2,n-i);
	}
	return ans;
}
string turn_two(int a)
{
	string ans="";
	while(a!=0)
	{
		ans=char(a%2+'0')+ans;
		a/=2;
	}
	return ans;
}

//xor
int x(int a1,int b1)
{
	string a=turn_two(a1),b=turn_two(b1);
	if(a.size()<b.size())
	{
		while(a.size()!=b.size())a='0'+a;
	}
	else if(b.size()<a.size())
	{
		while(a.size()!=b.size())b='0'+b;
	}
	string c="";
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])c+='1';
		else c+='0';
	}
	
	return turn_ten(c);
}

//main

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,in=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int on=0;
		cin>>a[i];
		for(int j=i;j>=1;j--)
		{
			if(j==i)b[i].push_back(a[i]);
			else
			{
				b[i].push_back(x(b[i][on++],a[j]));
			}
			if(b[i][on]==k)
			{
				at[in][1]=j;
				at[in][2]=i;
				in++;
			}
		}
	}
	int ans=in-1,maxx=-1,maxn=maxx;
	for(int i=1;i<in;i++)
	{
		a1[i].seat=i;
		for(int j=1;j<in;j++)
		{
			if(j==i)continue;
			if((at[i][1]<=at[j][2] && at[i][1]>=at[j][1])||(at[i][2]<=at[j][2] && at[i][2]>=at[j][1]))a1[i].disadvantage++;
		}
	}
	sort(a1+1,a1+in,judge);
	
	int att=1;
	while(a1[1].disadvantage!=0)
	{
		ans--,att=1;
		yseat[in-ans]=a1[1].seat;
		for(int i=1;i<=ans;i++)
		{
			a1[i].seat=0;
			a1[i].disadvantage=0;
		}
		for(int i=1;i<in;i++)
		{
			bool f=true;
			for(int u=1;u<=in-ans;u++)
			{
				if(i==yseat[u])
				{
					f=false;
					break;
				}
			}
			if(!f)continue;
			a1[att].seat=i;
			for(int j=1;j<in;j++)
			{
				bool fl=true;
				for(int u=1;u<=in-ans;u++)
				{
					if(j==yseat[u])
					{
						fl=false;
						break;
					}
				}
				if(!fl)continue;
				if(j==i)continue;
				if((at[i][1]<=at[j][2] && at[i][1]>=at[j][1])||(at[i][2]<=at[j][2] && at[i][2]>=at[j][1]))a1[att].disadvantage++;
			}
			att++;
		}
		sort(a1+1,a1+att,judge);
		
	}
	cout<<ans;
	
}