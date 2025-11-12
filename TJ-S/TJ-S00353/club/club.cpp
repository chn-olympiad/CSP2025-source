#include<bits/stdc++.h>
using namespace std;
int t;
int n;


int main()
{
	freopen("club.in","r",stdin);  
	freopen("club.out","w",stdout);
//=================================
	cin>>t;
	for(int i=0;i<t;t++)
	{
		cin>>n;
		int c[10005][3];
		int a;
		int f1=0,f2=0,f3=0;
		for(int j=0;j<n;j++)
		{
			cin>>c[j][0]>>c[j][1]>>c[j][2];
			if(c[j][0]>=c[j][1] && c[j][0]>=c[j][2] && n/2>=f1)
			{
				f1++;
				a=a+c[j][0];
				
			}
			else if(c[j][1]>=c[j][2] && n/2>=f2)
			{
				f2++;
				a=a+c[j][1];
				
			}
			else 
			{
				f3++;
				a=a+c[j][2];
				
			}
			
		}
		cout<<a<<endl;
	}
	
	
	
	return 0;
}
