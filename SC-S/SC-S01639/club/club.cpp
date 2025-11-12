#include <iostream>
using namespace std;
int main()
{
	long long t,n,ai_1,ai_2,ai_3,j=0,p;
	cin>>t;
	long long a_1=0,a_2=0,a_3=0;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		p=n/2;
		for (int i=1;i<=n;i++)
		{
			cin>>ai_1>>ai_2>>ai_3;
			if (ai_1>=ai_2)
			{
				if (ai_1>=ai_3)
				{
					a_1+=1;
					if (a_1<=p)
					{
						j+=ai_1;
					}
				}
			}
			if (ai_2>=ai_1)
			{
				if (ai_2>=ai_3)
				{
					a_2+=1;
					if (a_2<=p)
					{
						j+=ai_2;
					}
				}
			}
			if (ai_3>=ai_1)
			{
				if (ai_3>=ai_2)
				{
					a_3+=1;
					if (a_3<=p)
					{
						j+=ai_3;
					}
				}
			}
		}
		cout<<j;
	}
}