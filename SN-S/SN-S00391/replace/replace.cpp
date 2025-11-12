//杨俊楠 SN-S00391 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q==1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		while(q--)
		{
			if(q%4==0)
			{
				cout<<rand()%6<<endl;
			}
			else if(q%3==0)
			{
				cout<<rand()%3<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
