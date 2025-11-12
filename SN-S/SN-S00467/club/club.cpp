// 王嘉豪 SN-S00467 西安高新第一中学 


#include<bits/stdc++.h>
using namespace std;
int compare(int a,int b,int c)
{
	int n,m,x;
	n=max(a,b);
	m=max(b,c);
	x=max(n,m);
	return x;
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,a[n][3];
		int o;
		cin>>n;
		int m=n/2;
		int num;
		for(int j=1;j<=n;j++)
		{
			for(int s=1;s<=3;s++)
			{
				cin>>a[j][s];
			}			
		}
		for(int d=1;d<=n;d++)
		{
			
			o=compare(a[d][1],a[d][2],a[d][3]);
			num+=o;
		}
		cout<<num<<"1";
	}	

	
	return 0;
}
