#include<iostream>
#include<cmath>
using namespace std;
string F[50000][2];
string As[200000][2];
int m,n;
int cnt;
string getstr(int l,int r,string a)
{
	string b;
	for(int i=l;i<r;i++)
	{
		b+=a[i];
	}
	return b;
}
string chstr(int x,string str1,string str2)
{
	for(int s=x;s<str1.size()+x;s++)
	{
		str2[s]=str1[s-x];
	}
	return str2;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>F[i][0]>>F[i][1];
	}
	for(int i=0;i<n;i++)
	{
		cin>>As[i][0]>>As[i][1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int x=0;x+F[j][0].size()<=As[i][0].size();x++)
			{
				if(getstr(x,x+F[j][0].size(),As[i][0])==F[j][0])
				{
					if(chstr(x,F[j][1],As[i][0])==As[i][1])
					{
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
