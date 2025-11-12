#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn=200010;
ll n,m,sum;
string s[maxn][2],sa,sb;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	if(n*m>10000000000)
	{
		sum=n*m;
		cout<<sum<<endl;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cout<<i<<endl;
			sum=0;
			cin>>sa>>sb;
			for(int i=1;i<=n;i++)
			{
				ll la,lb;
				la=sa.find(s[i][1]);
				lb=sb.find(s[i][2]);
				if(la==lb&&la!=-1)
				{
					sum++;
				}
			}
			cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
