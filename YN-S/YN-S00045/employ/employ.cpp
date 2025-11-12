#include<bits/stdc++.h>
using namespace std;
int c[10000000];
string s[10000000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	int n,m,p;
	cin>>n>>m;
	string s;
	int l=s.size();
	l=n;
	for(int i=1;i<=l;i++)
	{
		cin>>s[i];
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
		}	
		if(s[i]==1&&c[i+1]<c[i]) n++;
		else n--;
		if(n==m)
		{
			p=n;
		}
		cout<<p;
		break;
	}
	return 0;
}
