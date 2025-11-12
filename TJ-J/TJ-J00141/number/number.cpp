#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string q,w,x;
	cin>>q;
	for(int i=0;i<q.size();i++)
	{
		if(q[i]<='9'&&q[i]>='0')
		{
			w+=q[i];
		}
	}
	for (int i=0;i<w.size();i++)
	{
		x[w[i]-'0']++;
	}
	for (int i=9;i>=0;i--)
	{
		for(int j=1;j<=x[i];j++)
		{
			cout <<i;
		}
	}
	return 0;
}
