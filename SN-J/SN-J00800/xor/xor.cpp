#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	int ans=0;
	string s="1";
	for(int i=1;i<=n;i++)
	    s+="0";
	string end="0";
	int l=0;
	while(s.find(end)!=string::npos)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')continue;
			int t=a[i];
			for(int j=i;j<=i+l;j++)
			{
				if(s[j]=='1')break;
				if(i!=j)t=(t^a[j]);
				if(t==k)
				{
					ans++;
					for(int r=i;r<=j;r++)
					    s[r]='1';
					i=j+1;
					break;
				}
			}
		}
		end+="0";
		l++;
	}
	cout<<ans<<endl;
	return 0;
}
