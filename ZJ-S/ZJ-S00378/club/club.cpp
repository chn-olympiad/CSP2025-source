#include <iostream>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c,cnt=0;
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>a>>b>>c;
			if(a>b)
			{
				if(a>c)
				{
					cnt+=a;
				}
				else
				{
					cnt+=c;
				}
			}
			else
			{
				if(b>c)
				{
					cnt+=b;
				}
				else
				{
					cnt+=c;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
