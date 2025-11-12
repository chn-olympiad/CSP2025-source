#include<iostream>
using namespace std;
long long bj[105][105];
	long long t,a1,b1,b2,b3,a2,a3,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);

	cin>>t;
	for(int k=1;k<=t;k++)
	{
		a1=b2=0;
		a2=b2=0;
		a3=b3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>bj[i][1]>>bj[i][2]>>bj[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			if(bj[i][1]>=bj[i][2]&&bj[i][1]>=bj[i][3]) 
			{
				a1++;
				b1+=bj[i][1];
			}
			else if(bj[i][2]>=bj[i][1]&&bj[i][2]>=bj[i][3]) 
			{
				a2++;
				b2+=bj[i][2];
			}
			else if(bj[i][3]>=bj[i][2]&&bj[i][3]>=bj[i][1]) 
			{
				a3++;
				b3+=bj[i][3];
			}
		}
		 cout<<b1+b2+b3<<endl;
	}
	
	return 0;
 } 
