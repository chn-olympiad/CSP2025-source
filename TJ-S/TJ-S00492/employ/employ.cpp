#include<bits/stdc++.h>
using namespace std;
int n,c[100005],ans,m=1;
string s;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n;
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		m*=i;
		cin>>c[i];
		if(c[i]==0)
		{
			ans++;
		}
	}
	cout<<m-ans;
	return 0;
}
