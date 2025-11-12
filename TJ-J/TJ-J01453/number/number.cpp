#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
char a[N];
char f[N];
bool flag[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int maxn=-1;
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			n++;
			a[j]=s[i];
			j++;
		}	
	}  
	for(int i=1;i<=n;i++)
	{
		int k=0;
		maxn=-1;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=maxn&&flag[j]==0)
			{
				maxn=a[j];
				k=j;
			}
		}
		flag[k]=1;
		f[i]=maxn;
	}
	for(int i=1;i<=n;i++) cout<<f[i];
	return 0;
}
