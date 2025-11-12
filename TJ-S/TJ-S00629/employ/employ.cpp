#include<bits/stdc++.h> 
using namespace std;

int c[505];
char s[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	
	cout<<m;
	
	return 0;
}
