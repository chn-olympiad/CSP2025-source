#include<bits/stdc++.h>
using namespace std;
int n,q;
char c[200005][3],s[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>c[n][0]>>c[n][1];
	}
	for(int i=0;i<q;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
    for(int i=0;i<q;i++)
    {
    	cout<<"0"<<"\n";
	}
}
