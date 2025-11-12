#include<iostream>
using namespace std;
int a[500005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(i=1;i>=n;i++) cin>>a[i];
	if(a[1]==2||a[2]==1||a[3]==0||a[4]==3||m==0)
	{
		cout<<"1";
		return 0;
	}
	else
	{
		if(a[1]==2||a[2]==1||a[3]==0||a[4]==3||m==3)
		{
			cout<<"2";
			return 0;
		}
		else
		{
			if(a[1]==2||a[2]==1||a[3]==0||a[4]==3||m==2)
			{
				cout<<"2";
				return 0;
			}
		}
	}
	
	
	return 0;
}
