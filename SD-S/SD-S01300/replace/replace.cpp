#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a;
string b[1000005][5];
string start[1000005];
string end[1000005];
int c;
int k = 1;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>a;
	for(int i = 1;i<=n;i++)
	{
		cin>>b[i][1]>>b[i][2];
	}
	for(int i = 1;i<=a;i++)
	{
		cin>>start[i]>>end[i];
	}
	while(k<=a)
	{
		for(int i = 0;i<=n;i++)
		{
			if(start[k].find(b[i][1]) or start[k] == b[i][1])
			{
				string begin = start[k];
				for(int j = start[k].find(b[i][1]);j<start[k].find(b[i][1])+b[i][1].length();j++)
				{
					begin[j] = b[i][2][j-start[k].find(b[i][1])];
				}
				if(begin == end[k])
				{
					c++;;
				}
			}
		}
		cout<<c<<endl;
		k++;
		c = 0;
	}
	return 0;
}

