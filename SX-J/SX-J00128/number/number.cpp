#include<bits/stdc++.h>
using namespace std;
string s;
long long maxx=LLONG_MIN;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		if(maxx<i)
		{
			maxx=i;
		}
	}
	cout<<maxx;
	return 0;
}