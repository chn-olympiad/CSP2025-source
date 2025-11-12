#include <bits/stdc++.h>
#include <algorithm>
bool pdsf(int a,int b,int c)
{
	
}
using namespace std;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int a1,a2,a3;
	int sum=0;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a1>>a2>>a3;
			if(a1>a2)
				sum+=max(a1,a3);
			if(a1<a2)
				sum+=max(a2,a3);
			if(a1==a2){
				if(a1>a3)
					sum+=max(a1,a2);
				if(a1<a3)
					sum+=max(a3,a2);
			}
										
		}
		cout<<sum<<endl;
		sum=0;
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
